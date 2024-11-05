class Solution:
    def minChanges(self, s: str) -> int:
        # if(len(s)%2==1) :
        #     return -1
        cng = 0
        for i in range(0,len(s),2):
            if s[i]!=s[i+1]:
                cng+=1
        return cng
