#!/usr/bin/env python

import re, sys

from complib.utils import *

NONE  =   0
OPT   =   1
MULT  =   2

stamps =  (
    ( "ident", "eq",  "strx" ),
    ( "ident", "sp",  "eq", "sp", "strx" ),
    )
flags = (
    ( NONE,  NONE,  NONE,),
    ( NONE, OPT,  NONE, OPT, NONE, ),
    )

# ------------------------------------------------------------------------
# Construct lexer, precompile regex, fill into array

class LinParse():

    def __init__(self, pvg):
        #print("linparse init")
        self.pvg = pvg
        # Check integrity
        for ss in range(len(stamps)):
            #print(len(stamps[ss]), len(flags[ss]) )
            if len(stamps[ss]) != len(flags[ss]):
                raise ValueError("Invalid flag len")

    def feed(self, arrx, buf):

        self.arrx = arrx
        self.buf = buf

        if self.pvg.verbose:
            for aa in arrx:
                print(" [", aa[0][1], pp(aa[1]), " ]", end = " ")
            print()

        # Walk all stamps, see if we have a match
        for idx in range(len(stamps)):
            bb = 0
            stamp = stamps[idx]; slen = len(stamp)
            flag = flags[idx]
            #for bb in range(slen):
            #    print("ss:", bb, stamp[bb], end = " ")
            #print()
            #for bb in range(slen):
            #    print("aa:",  bb, arrx[bb][0][1], end = " ")
            # Compare items
            istamp = iprog = 0
            for bb in range(slen):
                #print("flag:",
                if flag[iprog] & OPT:
                    iprog += 1
                    continue
                #if flag[bb] & MULT:
                #    pass
                if stamp[istamp] != arrx[iprog][0][1]:
                    break
                istamp += 1; iprog += 1

            print("break", "idx:", idx, "bb:", bb, "slen:", slen)
            if bb == slen - 1:
                print("stamp match", "idx:", idx, stamp, bb, );
            print()

# EOF
