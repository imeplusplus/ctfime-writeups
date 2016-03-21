#!/usr/bin/python

def strXor(plain, key='VC_TEM_QUE_ACHAR_A_CHAVE', encode=False, decode=False):
    from itertools import izip, cycle
    import base64
    if decode:
        plain = base64.decodestring(plain)
    xored = ''.join(chr(ord(x) ^ ord(y)) for (x,y) in izip(plain, cycle(key)))
    if encode:
        return base64.encodestring(xored).strip()
    return xored


plain = "One cookie to rule them all"

print(strXor(plain, encode=True))

#INPUT: One cookie to rule them all
#OUTPUT: DDojaS4qFAVdVX8ZX0NGB1hQf0Q3B1xaFBEv
