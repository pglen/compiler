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

        #print("itemx", "tprog =", tprog)
        '''  Compare items. Return end of scan point '''
        miss = istamp = iprog = 0
        while True:
            if istamp >= len(currstamp):
                print("break on stamp size")
                break
            while True:
                if tprog + iprog >= endd-start:
                    break
                if not self.arrx[tprog + iprog][4][0]:
                    break
                #print("skip",  self.arrx[tprog + iprog])
                iprog += 1

            if tprog + iprog >= endd-start:
                break
            #print("istamp", istamp)
            if currstamp[istamp][1] & M:
                # Walk otional multi
                while 1:
                    if currstamp[istamp][0] != self.arrx[tprog + iprog][0][1]:
                        break
                    #print("mark", "idx =", idx, self.arrx[tprog + iprog], tprog + iprog)
                    self.arrx[tprog + iprog][4][0] = 1
                    iprog += 1
                istamp += 1
                #break
            if currstamp[istamp][1] & A:
                ebound = currstamp[istamp + 2][0]
                print("accum:", "skip:", end = " ")
                while 1:
                    print(self.arrx[tprog + iprog][0][1], end = " ")
                    if ebound == self.arrx[tprog + iprog][0][1]:
                        break
                    iprog += 1
                print()
                prarr(self.arrx, "stamp A opt:")
                #tprog += iprog
                break
            #print("stamp:", currstamp[istamp][0], "\titem:", self.arrx[tprog + iprog][0][1])
            if currstamp[istamp][0] != self.arrx[tprog + iprog][0][1]:
                miss = True
                iprog += 1
                break
            istamp += 1; iprog += 1    # step forward
            # Complete?
            if istamp >= len(currstamp):
                if not miss:
                    #print("stamp match:", "istamp=", istamp, currstamp);
                    call(self, tprog, iprog)
                    self.restart = True
                break
        return iprog

    def stampx(self, idx, start, endd):
        tprog = start
        stamp = self.stamps[idx][0];
        call = self.stamps[idx][1];
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
            tprog += self.itemx(stamp, tprog, start, endd, call)

    def _feed(self, start, endd):
        print("_feed: ", start, endd)
        self.restart = False;
        idx = 0
        # Walk all stamps, see if we have a match
        #for idx in range(len(stamps)):
        while True:
            if idx >= len(self.stamps):
                if  not self.restart:
                    break
                idx = 0
                self.restart = False
                print("restarted at", start)
            #for tprog in range(len(arrx)):
            self.stampx(idx, start, endd)
            idx += 1
# EOF
