#!/usr/bin/env python

import re, sys

from . import lexdef, stack

# ------------------------------------------------------------------------
# Construct lexer, precompile regex, fill into array

class Lexer():

    def __init__(self, tokens):

        # Pre-compile tokens
        for cnt in range(len(tokens)):
            try:
                tokens[cnt][3] = re.compile(tokens[cnt][2])
            except:
                print("Cannot precomp regex at: '", tokens[cnt][2], "'", sys.exc_info())
                #raise
                break
            cnt += 1

        #for aa in tokens:
        #    print( aa)

        # Remember args
        self.tokens  = tokens
        self.state =  lexdef.INI_STATE
        self.statstack = stack.Stack()
        self.straccum = ""
        self.escaccum = ""
        self.linenum = 0
        self.lastline = 0

    # Call this for every token

    def lexiter(self, state, pos, strx):
        #print (strx[pos:])
        for ss, bb, cc, dd, ee in self.tokens:
            #print (bb, cc)
            if ss != self.state:
                continue
            mmm = dd.match(strx, pos)
            if mmm:
                #print("mmm", mmm, dd)
                #print (mmm.end() - mmm.start(), strx[mmm.start():mmm.end()])
                mstr = mmm.string[mmm.start():mmm.end()]
                tt = [ ss, bb, cc, dd, ee, mstr, mmm ]
                return tt
        return None;

    def feed(self, data, stack):
        lastpos = 0; pos = 0; lenx = len(data)
        while True:
            if pos >= lenx:
                break;
            tt = self.lexiter(self, pos, data)
            if tt == None:
                break
            if tt[6]:
                # skip to token end
                beg = pos; pos = tt[6].end()
                #print("tt", tt)
                #print  (tt[1], "'" + data[tt[1].start():tt[1].end()] + "' - ",)
                #print   ("'" + data[tt[1].start():tt[1].end()] + "' - ",)
                if  tt[1] == "nl":
                    self.linenum += 1
                    print("Newline at ", tt[1], pos)
                    self.lastline = beg

                #tt.append(self.linenum)
                #tt.append(beg - self.lastline)
                #print(tt)

                # Change state if needed
                if tt[4] != lexdef.STATE_NOCH:
                    if tt[1] ==  "quote":
                        print("Change str state", tt[1])
                        self.straccum = ""
                        self.statstack.push(self.state)
                        self.state = lexdef.STR_STATE

                    elif tt[0] ==  "bsl":
                        #print("Change bs state up")
                        self.statstack.push(self.state)
                        self.state = lexdef.ESC_STATE

                if tt[4] == lexdef.STATE_DOWN:
                    #print("Change str state down:", self.straccum)
                    self.straccum += '"';
                    tt[1] = 'strx';
                    tt[5] = self.straccum
                    stack.push(tt)
                    print("accum", self.straccum)
                    self.straccum = ""
                    self.state = self.statstack.pop()

                elif tt[4] == lexdef.STATE_ESCD:
                    #print("Change bs state down:", _p(self.escaccum))
                    self.straccum += self.escaccum
                    self.escaccum = ""
                    self.state = self.statstack.pop()
                else:
                    if self.state == lexdef.INI_STATE:
                        stack.push(tt)

                # Fill accumulators:
                if  self.state == lexdef.STR_STATE:
                    self.straccum += tt[5]

                if  self.state == lexdef.ESC_STATE:
                    self.escaccum += tt[5]

                #print(self.state, tt[0], lexdef.rtok[tt[0]], "\t", tt[2])
            else:
                pos += 1  # step to next char

if __name__ == "__main__":
    print ("This module was not meant to operate as main.")
    #print("tok", tokens)

# EOF

