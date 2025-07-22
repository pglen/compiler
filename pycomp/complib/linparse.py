#!/usr/bin/env python

import re, sys

from complib.utils  import *

from complib.linfunc import *
from complib.lindef import *

# ------------------------------------------------------------------------
# Construct lexer, precompile regex, fill into array

class LinParse():

    def __init__(self, stamps, pvg = None):
        #print("linparse init")
        self.pvg = pvg
        defpvg(pvg)
        funcpvg(pvg)
        self.stamps = stamps
        # Check integrity
        for ss in range(len(self.stamps)):
            pass

    def skiplen(self, stampx):
        ret = 0 ; uprog = 0; umax = len(stampx)
        while 1:
            if uprog >= umax:
                break
            if stampx[uprog][1] & A:
                pass
            #elif stampx[uprog][1] & M:
            #    pass
            else:
                ret += 1
            uprog += 1
        return ret

    def feed(self, arrx, buf):
        self.buf = buf
        self.arrx = arrx
        if self.pvg.verbose > 1:
            print("stamps len =", len(self.stamps), "arrx len =", len(self.arrx))
        if self.pvg.verbose:
            for aa in arrx:
                print(" [", aa[0][1], pp(aa[1]), aa[4][0], " ]", end = " ")
                #print(" [", aa, "] ", end = " ")
            print()
        self._feed(0, len(arrx))

    def itemx(self, currstamp, tprog, start, endd, call):

        '''  Compare items. Return end of scan point '''
        print("itemx", "tprog =", tprog)

        miss = istamp = iprog = 0
        skiplen = self.skiplen(currstamp)
        while True:
            if istamp >= len(currstamp):
                if self.pvg.pgdebug: print("break on end of stamp")
                break
            while True:
                if tprog + iprog >= endd-start:
                    break
                if not self.arrx[tprog + iprog][4][0]:
                    break
                print("skip",  self.arrx[tprog + iprog])
                iprog += 1

            if tprog + iprog >= endd-start:
                if  self.pvg.pgdebug:
                    print("break on end of buffer", "tprog =", tprog, "iprog =", iprog)
                break
            if currstamp[istamp][1] & P:
                if currstamp[istamp][0] == self.arrx[tprog + iprog][0][1]:
                    pass
                else:
                    istamp += 1
            if currstamp[istamp][1] & M:
                # Walk optional multi
                while 1:
                    if currstamp[istamp][0] != self.arrx[tprog + iprog][0][1]:
                        break
                    #print("mark", "idx =", self.arrx[tprog + iprog],
                    #                tprog + iprog)
                    self.arrx[tprog + iprog][4][0] = 1
                    iprog += 1
                istamp += 1
            #if currstamp[istamp][1] & A:
            #    istamp += 2    # End of this expression
            #    ebound = currstamp[istamp][0]
            #    #print("accum skip till:", "'"+ebound+"'", end = " => ")
            #    while 1:
            #        #print(self.arrx[tprog + iprog][0][1], end = " ")
            #        if ebound == self.arrx[tprog + iprog][0][1]:
            #            break
            #        iprog += 1
            #    #print()
            #    #iprog += 1
            #    if  self.pvg.pgdebug:
            #        prarr(self.arrx[tprog : iprog+1], "stamp A opt:")
            print("before: istamp =", istamp, "iprog =", iprog, "tprog =", tprog)
            print("currstamp:", "'"+currstamp[istamp][0]+"'", "\titem:",
                              "'"+self.arrx[tprog + iprog][0][1]+"'")
            if currstamp[istamp][0] != self.arrx[tprog + iprog][0][1]:
                miss = True
                #iprog += 1
                print("miss", )
                break
            # Complete?
            #print("istamp =", istamp, "iprog", iprog, "skiplen =", skiplen,
            #                    "len =", len(currstamp))
            istamp += 1;
            iprog += 1    # step forward
            if istamp >= skiplen:
                if not miss:
                    if self.pvg.pgdebug > 3:
                        print("stamp match:", "tprog =", tprog,
                                 "istamp=", istamp, "currstamp =", currstamp);
                    call(self, tprog, iprog )
                    self.restart = True
                break

        time.sleep(0.3)
        return iprog

    def stampx(self, idx, start, endd):
        tprog = start
        stamp = self.stamps[idx][0];
        call  = self.stamps[idx][1];
        #print("search stamp =", stamp, "tprog =", tprog)
        while True:
            # Walk all indexes see if we have a match
            if tprog >= endd:
                break;
            if self.pvg.pgdebug > 4:
                print("\n stamps:\t",  tprog, end=" " )
                for bb in range(len(stamp)):
                    print(stamp[bb][0], end = " ")
                print("\n", "arrx:", idx, "\t", tprog, end=" ")
                for bb in range(len(stamp)+6):
                    if tprog + bb < len(self.arrx):
                        print(self.arrx[tprog + bb][0][1], end = " ")
            xprog = self.itemx(stamp, tprog, start, endd, call)
            break
            if not xprog:
                xprog = 1               # assure forward motion
            #print("xprog =", xprog)
            tprog += xprog

    def _feed(self, start, endd):
        if self.pvg.pgdebug > 2:
            print("_feed: ", start, endd)
        if self.pvg.pgdebug > 3:
            prarr(self.arrx[start : endd], "recu")
        self.restart = False;
        idx = 0
        # Walk all stamps, see if we have a match
        #for idx in range(len(stamps)):
        while True:
            if idx >= len(self.stamps):
                if not self.restart:
                    break
                idx = 0
                self.restart = False
                if self.pvg.pgdebug: print("restarted at", start)
            #for tprog in range(len(arrx)):
            self.stampx(idx, start, endd)
            idx += 1
# EOF
