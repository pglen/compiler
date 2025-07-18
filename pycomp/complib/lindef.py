#!/usr/bin/env python

''' Definitions for the linear parser '''

from complib.utils import *

N   =   0     # _No_ flag
P   =   1     # Op_P_ional
M   =   2     # _M_ultiple

def setpvg(xpvg):
    global pvg
    pvg = xpvg

# Functions to call on stamp match

def func1(idx, tprog):
    print("match func1 idx", idx, "tprog =", tprog)

def func2(idx, tprog):
    print("match func2 idx", idx, "tprog =", tprog)

def func3(idx, tprog):
    print("match func3 idx", idx, "tprog =", tprog)

def func_add(arrx, idx, tprog):
    print("match add idx =", idx, "tprog =", tprog, "slen =", len(stamps[idx][0]))
    if pvg.pgdebug > 2:
        prarr(arrx, "arrx add pre: ")
    ttt = list(arrx[tprog]) ; ttt2 = list(arrx[tprog + 4])
    ttt[1] = int(ttt[1]) + int(ttt2[1])
    arrx[tprog] = ttt
    # Del this set except current
    for aa in range(len(stamps[idx][0])-1, 0, -1):
        del arrx[tprog + aa]
    if pvg.pgdebug > 2:
        prarr(arrx, "arrx add: ")

def func_mul(arrx, idx, tprog):
    print("match mul idx =", idx, "tprog =", tprog, "slen =", len(stamps[idx][0]))
    #print("arrx2:", arrx)
    #if pvg.pgdebug > 2:
    #    prarr(arrx, "arrx mul pre: ")
    for aa in range(len(stamps[idx][0])):
        #item = arrx[tprog + aa]
        #print(item[1], item)
        pass
    ttt = list(arrx[tprog]) ; ttt2 = list(arrx[tprog + 4])
    ttt[1] = int(ttt[1]) * int(ttt2[1])
    arrx[tprog] = ttt
    # Del this set except curr
    for aa in range(len(stamps[idx][0])-1, 0, -1):
        del arrx[tprog + aa]
    if pvg.pgdebug > 2:
        prarr(arrx, "arrx mul: ")

# There are the entries to be matched agains the parse array.
#       (parse items,flags) ...                              function
#       --------------------------                           ----------

stamps =  (
    ( (("num",N),  ("sp",N),  ("star",N), ("sp",N),  ("num",N)), func_mul),
    ( (("num",N),  ("sp",P|M),("plus",N), ("sp",P|M),("num",N)), func_add),
    ( (("ident",N),("sp",P|M),("eq",N),   ("sp",P|M),("num",N)), func1),
    ( (("ident",N),("eq",N),  ("strx",N)), func2),
    ( (("ident",N),("sp",P|M),("eq",N),   ("sp",P|M),("strx",N)), func3),
  )

# EOF
