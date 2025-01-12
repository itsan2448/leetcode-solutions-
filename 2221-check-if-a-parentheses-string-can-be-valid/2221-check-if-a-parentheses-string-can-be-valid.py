class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        
        l=len(s)
        if l%2==1:
            return False
        
        o,c=0,0
        for i in range(l):
            if s[i]=='(' or locked[i]=='0':
                o+=1
            else:
                c+=1
            if c>o:
                return False
        
        o,c=0,0
        for i in range(l-1,-1,-1):
            if s[i]==')' or locked[i]=='0':
                c+=1
            else:
                o+=1
            if c<o:
                return False
        return True