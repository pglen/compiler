#!/usr/bin/env python

''' functions for the linear parser '''

import operator

from complib.utils import *

def funcpvg(xpvg):
    global pvg
    pvg = xpvg

# Functions to call on stamp match

def func_dummy(self2, idx, tprog, iprog):
    if pvg.verbose:
        print("match dummy idx =", idx, "tprog =", tprog, "iprog=", iprog, "slen =", len(stamps[idx][0]))

def func_str(self2, idx, tprog, iprog):
    print("match str idx =", idx, "tprog =", tprog, "iprog=", iprog, "slen =", len(stamps[idx][0]))
    if pvg.pgdebug > 2:
        prarr(self2.arrx[tprog:tprog+iprog], "arrx str pre: ")
    sys.exit(0)

def func_paren(self2, tprog, iprog):

    if pvg.verbose:
        print("match paren tprog =", tprog, "iprog=", iprog)
    if pvg.pgdebug > 2:
        prarr(self2.arrx[tprog:tprog+iprog], "arrx paren pre: ")

    #self2._feed(tprog + 1, tprog+iprog - 1)

    for ss in range(tprog+1, tprog+iprog):
        if self2.arrx[ss][4][0]:  continue
        #prarr(self2.arrx[ss:ss+1], "delx")
        self2.arrx[ss][4][0] = 1

    if pvg.pgdebug > 2:
        prarr(self2.arrx[tprog:tprog+iprog], "arrx paren post: ")

def _func_arith(self2, opstr, tprog, iprog):

    uprog = 0
    while 1:
        if uprog >= iprog: return
        if self2.arrx[tprog + uprog][4][0]: uprog += 1 ; continue
        if opstr == self2.arrx[tprog + uprog][0][1]:
            break
        uprog += 1
    #print("to =", self2.arrx[tprog + uprog][0][1])
    while 1:
        if uprog >= iprog: return
        if self2.arrx[tprog + uprog][4][0]: uprog += 1 ; continue
        if "num" == self2.arrx[tprog + uprog][0][1]:
            break
        uprog += 1
    #print("to =>", self2.arrx[tprog + uprog][0][1])
    ttt = list(self2.arrx[tprog]) ; ttt2 = list(self2.arrx[tprog+uprog])
    if opstr == "+":
        ttt[1] = int(ttt[1]) + int(ttt2[1])
    elif opstr == "*":
        ttt[1] = int(ttt[1]) * int(ttt2[1])
    else:
        print("Invalid op:", opstr);

    self2.arrx[tprog] = ttt

    for ss in range(tprog+1, tprog+iprog):
        if self2.arrx[ss][4][0]:  continue
        #prarr(self2.arrx[ss:ss+1], "delx")
        self2.arrx[ss][4][0] = 1

def func_mul(self2, tprog, iprog):
    if pvg.verbose:
        print("match mul tprog =", tprog, "iprog=", iprog)
    if pvg.pgdebug > 2:
        prarr(self2.arrx[tprog:tprog+iprog], "arrx mul pre: ")
    _func_arith(self2, "*", tprog, iprog)
    if pvg.pgdebug > 2:
        prarr(self2.arrx[tprog:tprog+iprog], "arrx mul post: ")

def func_add(self2, tprog, iprog):
    if pvg.verbose:
        print("match add tprog =", tprog, "iprog=", iprog)
    if pvg.pgdebug > 2:
        prarr(self2.arrx[tprog:tprog+iprog], "arrx add pre: ")
    _func_arith(self2, "+", tprog, iprog)
    if pvg.pgdebug > 2:
        prarr(self2.arrx[tprog:tprog+iprog], "arrx add post: ")

# EOF
