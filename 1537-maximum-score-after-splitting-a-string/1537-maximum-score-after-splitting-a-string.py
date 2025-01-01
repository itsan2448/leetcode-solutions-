class Solution:
    def maxScore(self, s: str) -> int:
        pre=[]
        ans=float('-inf')
        pre.append(ord(s[0])-ord('0'))

        for i in range(1,len(s)):
            pre.append(pre[i-1]+ord(s[i])-ord('0'))
        
        z=0
        for i in range(len(s)-1):
            if s[i]=='0':
                z+=1            
            ans=max(ans,z+pre[len(s)-1]-pre[i])
        
        return ans
        