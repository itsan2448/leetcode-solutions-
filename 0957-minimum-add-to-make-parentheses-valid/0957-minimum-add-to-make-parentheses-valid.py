class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        o,c=0,0 # unmatched ( and )
        for i in range(len(s)):
            if s[i]=='(':
                o+=1
            elif s[i]==')' and o>0:
                o-=1
            else :
                c+=1                      

        return o+c
        
        