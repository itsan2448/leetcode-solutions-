class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n,z=len(s),len(shifts)
        ap=[0]*(n+1)
        for b,e,d in shifts:
            ap[b]+=(d*2-1)
            ap[e+1]-=(d*2-1)
        ap=list(accumulate(ap))
        s0=[]
        for i,c in enumerate(s):
            t=(ap[i]+ord(c)-97)%26 + 97
            if t<97:
                t+=26
            s0.append(chr(t))
        return "".join(s0)