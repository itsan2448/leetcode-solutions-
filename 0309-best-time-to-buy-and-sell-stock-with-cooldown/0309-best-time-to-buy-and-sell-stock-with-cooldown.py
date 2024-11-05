class Solution:
    def maxProfit(self, p: List[int]) -> int:
        n = len(p)
        ''' 
        dp = [[0]*2 for _ in range(n+2)]

        for i in range(n-1,-1,-1):                            
            dp[i][1] = max(-p[i] + dp[i+1][0],dp[i+1][1])                
            dp[i][0] = max(p[i] + dp[i+2][1], dp[i+1][0])
        
        return dp[0][1]

        '''

        front2 = [0]*2
        front1 = [0]*2
        cur = [0]*2

        for i in range(n-1,-1,-1):                            
            cur[1] = max(-p[i] + front1[0],front1[1])                
            cur[0] = max(p[i] + front2[1], front1[0])
            front2 = front1[:]
            front1 = cur[:]
        
        return cur[1]