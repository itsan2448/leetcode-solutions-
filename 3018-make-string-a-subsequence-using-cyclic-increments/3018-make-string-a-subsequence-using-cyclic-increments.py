class Solution:
    def canMakeSubsequence(self, s1: str, s2: str) -> bool:
        if len(s2)>len(s1):
            return False
        if s1==s2 :
            return True
        i,j=0,len(s2)
        for c in s1:
            if i<j and (ord(s2[i])-ord(c))%26<2:
                i+=1
        return i==j
        