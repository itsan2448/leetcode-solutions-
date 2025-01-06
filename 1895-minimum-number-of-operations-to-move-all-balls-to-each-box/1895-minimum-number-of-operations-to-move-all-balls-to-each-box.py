class Solution:
    def minOperations(self, b: str) -> List[int]:
        n=len(b)
        ans=[0]*n
        preC=0
        preS=0
        for i in range(n):
            ans[i]=preC*i-preS
            if b[i]=='1':
                preC+=1
                preS+=i
        sufC=0
        sufS=0
        for i in range(n-1,-1,-1):
            ans[i]+=sufS-sufC*i
            if b[i]=='1':
                sufC+=1
                sufS+=i
        return ans