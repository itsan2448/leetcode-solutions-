class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        i,j,c=-1,-1,0
        for k in range(len(s1)):
            if s1[k]!=s2[k]:
                c+=1
                if i==-1:
                    i=k
                elif j==-1:
                    j=k
        
        if c==0 or c==2 and s2[j]==s1[i] and s1[j]==s2[i]:
            return True
        return False

