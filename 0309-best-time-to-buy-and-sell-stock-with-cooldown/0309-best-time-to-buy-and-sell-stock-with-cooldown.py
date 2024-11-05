class Solution:
    def maxProfit(self, p: List[int]) -> int:
        n = len(p)
         
        dp = [[0]*2 for _ in range(n+2)]

        for i in range(n-1,-1,-1):                            
            dp[i][1] = max(-p[i] + dp[i+1][0],dp[i+1][1])                
            dp[i][0] = max(p[i] + dp[i+2][1], dp[i+1][0])
        
        return dp[0][1]