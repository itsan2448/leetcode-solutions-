class Solution:
    def maxProfit(self, K: int, p: List[int]) -> int:
        n=len(p)
        after = [[0]*(K+1)  for j in range(2)]
        cur = [[0]*(K+1)  for j in range(2)]

        for i in range(n-1,-1,-1):
            for j in range(2):
                for k in range(1,K+1): #cap=0, base case
                    if j==1:
                        cur[j][k]= max(-p[i]+ after[0][k], after[1][k])
                    else :
                        cur[j][k]=max(p[i]+ after[1][k-1], after[0][k])
            after = cur
        return cur[1][K]