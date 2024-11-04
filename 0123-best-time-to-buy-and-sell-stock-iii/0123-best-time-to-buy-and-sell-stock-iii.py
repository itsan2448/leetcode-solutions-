class Solution:
    def f(self,buy, cap, ind, p,n,dp):
        if cap==0: 
            return 0
        if ind==n:
            return 0
        if dp[ind][buy][cap]!= -1:
            return dp[ind][buy][cap]
        if buy:
            dp[ind][buy][cap]= max(-p[ind]+self.f(0,cap,ind+1,p,n,dp),self.f(1,cap,ind+1,p,n,dp))
        else:
            dp[ind][buy][cap]= max(p[ind]+self.f(1,cap-1,ind+1,p,n,dp),self.f(0,cap,ind+1,p,n,dp))
        return dp[ind][buy][cap]
                
    def maxProfit(self, p: List[int]) -> int:
        
        n=len(p)
        dp=[[[-1]*3 for i in range(2)] for j in range(n)]
        return self.f(1,2,0,p,n,dp)

        


                    
