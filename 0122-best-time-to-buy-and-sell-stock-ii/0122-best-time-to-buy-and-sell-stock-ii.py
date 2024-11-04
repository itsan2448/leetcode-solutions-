class Solution:
    
    def maxProfit(self, p: List[int]) -> int:
        n = len(p)
                
        dp=[[0]*2 for _ in range(n+1)]
        
        # base case
        dp[n][0]=dp[n][1]=0

        for i in range (n-1,-1,-1):                            
            for j in range(2):
                profit =0
                if j:
                    profit = max(-p[i]+dp[i+1][0],dp[i+1][1])
                else :
                    profit = max(p[i]+dp[i+1][1],dp[i+1][0])
                dp[i][j] = profit
            
        # j=1 coz, we should be in the position to buy 
        return dp[0][1]