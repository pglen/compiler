#!/usr/bin/env python

import re, sys

from complib.utils import *

N   =   0     # No flag
P   =   1     # Optional
M   =   2     # Multiple

def func1(idx, idx2):
    print("match1 idx", idx, idx2)
    pass
def func2(idx, idx2):
    print("match2 idx", idx, idx2)
    pass
def func3(idx, idx2):
    print("match3 idx", idx, idx2)
    pass

stamps =  (
    ( (("ident",N),("sp",P|M),("eq",N),("sp",P|M),("num",N)), func1),
    ( (("ident",N),("eq",N),("strx",N)), func2),
    ( (("ident",N), ("sp",P|M),("eq",N),("sp",P|M),("strx",N)), func3),
    )

# ------------------------------------------------------------------------
# Construct lexer, precompile regex, fill into array

class LinParse():

    def __init__(self, pvg):
        #print("linparse init")
        self.pvg = pvg
        # Check integrity
        for ss in range(len(stamps)):
            pass
            #print(len(stamps[ss]), len(flags[ss]) )
            #if len(stamps[ss]) != len(flags[ss]):
            #    raise ValueError("Invalid flag len")

    def feed(self, arrx, buf):
        self.arrx = arrx
        self.buf = buf
        if self.pvg.verbose:
            for aa in arrx:
                print(" [", aa[0][1], pp(aa[1]), " ]", end = " ")
            print()
        # Walk all stamps, see if we have a match
        for idx2 in range(len(arrx)):
            # Walk all stamps, see if we have a match
            for idx in range(len(stamps)):
                bb = 0
                stamp = stamps[idx][0]; slen = len(stamp)
                '''
                print("stamps: ", end="")
                for bb in range(slen):
                    print(stamp[bb][0], end = " ")
                print("\n  arrx: ", end="")
                for bb in range(slen+6):
                    if idx2 + bb < len(arrx):
                        print(arrx[idx2 + bb][0][1], end = " ")
                '''
                # Compare items
                istamp = iprog = miss = 0
                for bb in range(slen):
                    if idx2 + iprog >= len(arrx):
                        break
                    #if stamp[istamp][1] & P:
                    #    istamp += 1
                    #    continue
                    if stamp[istamp][1] & M:
                        while 1:
                            if stamp[istamp][0] != arrx[idx2 + iprog][0][1]:
                                break
                            iprog += 1
                            #print('mult', stamp[istamp][0])
                        istamp += 1
                        continue

                    if stamp[istamp][0] != arrx[idx2 + iprog][0][1]:
                        miss = True
                        break
                    istamp += 1; iprog += 1
                #print("break", "idx:", idx, "bb:", bb, "slen:", slen)
                #print()
                if not miss:
                    #print("stamp match:", "idx =", idx) #, stamp);
                    stamps[idx][1](idx, idx2)
# EOF
