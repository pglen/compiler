#!/usr/bin/env python

import re, sys

from complib.utils  import *
from complib.lindef import *

# ------------------------------------------------------------------------
# Construct lexer, precompile regex, fill into array

class LinParse():

    def __init__(self, pvg):
        #print("linparse init")
        self.pvg = pvg
        setpvg(pvg)
        # Check integrity
        for ss in range(len(stamps)):
            pass
            #print(len(stamps[ss]), len(flags[ss]) )
            #if len(stamps[ss]) != len(flags[ss]):
            #    raise ValueError("Invalid flag len")

    def feed(self, arrx, buf):
        self.buf = buf
        self.arrx = arrx
        if self.pvg.verbose:
            print("stamps len =", len(stamps), "arrx len =", len(self.arrx))
        if self.pvg.verbose > 1:
            for aa in arrx:
                print(" [", aa[0][1], pp(aa[1]), " ]", end = " ")
            print()
        restart = False;
        idx = 0
        # Walk all stamps, see if we have a match
        #for idx in range(len(stamps)):
        while True:
            if idx >= len(stamps):
                if  not restart:
                    break
                idx = 0
            #for tprog in range(len(arrx)):
            tprog = 0
            #restart = False
            while True:
                miss = 0
                # Walk all indexeds see if we have a match
                if tprog >= len(arrx):
                    break;
                stamp = stamps[idx][0]; slen = len(stamp)
                if self.pvg.pgdebug > 4:
                    print("\n stamps:\t", tprog, end=" " )
                    for bb in range(slen):
                        print(stamp[bb][0], end = " ")
                    print("\n", "arrx:", idx, "\t", tprog, end=" ")
                    for bb in range(slen+6):
                        if tprog + bb < len(arrx):
                            print(arrx[tprog + bb][0][1], end = " ")
                # Compare items
                bb = istamp = iprog = 0
                for bb in range(slen):
                    if tprog + iprog >= len(arrx):
                        miss = True # not enough entries, set miss
                        break
                    #if stamp[istamp][1] & P:
                    #    istamp += 1
                    #    continue
                    if stamp[istamp][1] & M:
                        pass
                        # Walk otional multi
                        #while 1:
                        #    if stamp[istamp][0] != arrx[tprog + iprog][0][1]:
                        #        break
                        #    iprog += 1
                        #    #print('mult', stamp[istamp][0])
                        #istamp += 1
                        #continue
                    if stamp[istamp][0] != arrx[tprog + iprog][0][1]:
                        miss = True
                        break
                    istamp += 1; iprog += 1    # step forward
                #print("break", "idx:", idx, "bb:", bb, "slen:", slen)
                #print()
                if not miss:
                    #print("stamp match:", "idx =", idx) #, stamp);
                    stamps[idx][1](arrx, idx, tprog)
                    restart = True
                    #idx = -1    # Restart from below as inc is at the end
                    #tprog = 0
                    break
                tprog += 1
            idx += 1
# EOF
