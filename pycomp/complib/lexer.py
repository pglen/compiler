#!/usr/bin/env python

import re, sys

from . import lexdef, stack

# ------------------------------------------------------------------------
# Construct lexer, precompile regex, fill into array

class Lexer():

    def __init__(self, xtokens, pvg):

        # Pre-compile tokens
        self.pvg = pvg
        self.tokens = []
        for idx in range(len(xtokens)):
            try:
                 ccc = re.compile(xtokens[idx][2])
            except:
                print("Cannot precomp regex at: ", idx,
                            "'", xtokens[idx][2], "'", sys.exc_info())
                raise
            self.tokens.append((xtokens[idx], ccc))

        if self.pvg.verbose > 2:
            for aa in self.tokens:
                print("token:", aa)

        # Remember args
        self.state =  lexdef.INI_STATE
        self.statstack = stack.Stack()
        self.straccum = ""
        self.escaccum = ""
        self.linenum = 0
        self.lastline = 0
        self.start_tt = None

    # Call this for every token

    def _lexiter(self, pos, strx):
        #print (strx[pos:])
        for ttt, vv in self.tokens:
            #print (ttt, vv)
            if ttt[0] != self.state:
                 continue
            mmm = vv.match(strx, pos)
            if mmm:
                #print (mmm.end() - mmm.start(), strx[mmm.start():mmm.end()])
                mstr = mmm.string[mmm.start():mmm.end()]
                # Add empty at end for state information
                tt = ( ttt, mstr, mmm.start(), mmm.end(), [] )
                return tt
        return None;

    def feed(self, data, res):
        lastpos = 0; pos = 0; lenx = len(data)
        while True:
            if pos >= lenx:
                break;
            tt = self._lexiter(pos, data)
            #print(tt)
            if tt == None:
                break
            if tt[3]:
                # skip to token end
                beg = pos; pos = tt[3]
                #print("tt", tt)
                if  tt[1] == "nl":
                    self.linenum += 1
                    print("Newline at ", tt[1], pos)
                    self.lastline = beg

                #tt.append(self.linenum)
                #tt.append(beg - self.lastline)
                #print(tt)

                # Change state if needed
                if tt[0][3] != lexdef.STATE_NOCH:
                    #if tt[0][1] ==  "quote":
                    if tt[0][3] == lexdef.STR_STATE:
                        #print("Change str state with", tt[2])
                        self.straccum = ""
                        self.start_tt = tt
                        self.statstack.push(self.state)
                        self.state = lexdef.STR_STATE

                    elif tt[0][1] ==  "bsl":
                        #print("Change bs state up")
                        self.statstack.push(self.state)
                        self.state = lexdef.ESC_STATE

                if tt[0][3] == lexdef.STATE_DOWN:
                    if self.state == lexdef.STR_STATE:
                        #print("Change str state down:", self.straccum)
                        self.straccum += '"';

                        # This converts the read only list
                        ttt = list(tt)
                        ttt[0] = list(ttt[0])
                        ttt[0][1] = 'strx';
                        ttt[1] = self.straccum
                        ttt[2] = self.start_tt[2]
                        #print("ttt", ttt)
                        # BAck to read only list
                        ttt[0] = tuple(ttt[0])
                        ttt = tuple(ttt)
                        #stack.push(ttt)
                        res.append(ttt)

                    #print("accum", self.straccum)
                    self.straccum = ""
                    self.state = self.statstack.pop()

                elif tt[0][3] == lexdef.STATE_ESCD:
                    #print("Change bs state down:", _p(self.escaccum))
                    self.straccum += self.escaccum
                    self.escaccum = ""
                    self.state = self.statstack.pop()
                else:
                    if self.state == lexdef.INI_STATE:
                        #stack.push(tt)
                        res.append(tt)

                # Fill accumulators:
                if  self.state == lexdef.STR_STATE:
                    #print("accum: ", tt[2])
                    self.straccum += tt[1]

                if  self.state == lexdef.ESC_STATE:
                    self.escaccum += tt[2]

                #print(self.state, tt[0], lexdef.rtok[tt[0]], "\t", tt[2])
            else:
                pos += 1  # step to next char

if __name__ == "__main__":
    print ("This module was not meant to operate as main.")
    #print("tok", tokens)

# EOF

