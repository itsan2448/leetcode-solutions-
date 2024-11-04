class Solution:
    '''
    def f(self,buy, cap, ind, p,n,dp):
        # memoisation
        if cap==0 or ind==n: 
            return 0
        
        if dp[ind][buy][cap]!= -1:
            return dp[ind][buy][cap]
        if buy:
            dp[ind][buy][cap]= max(-p[ind]+self.f(0,cap,ind+1,p,n,dp),self.f(1,cap,ind+1,p,n,dp))
        else:
            dp[ind][buy][cap]= max(p[ind]+self.f(1,cap-1,ind+1,p,n,dp),self.f(0,cap,ind+1,p,n,dp))
        return dp[ind][buy][cap]
    '''

    def maxProfit(self, p: List[int]) -> int:
        
        n=len(p)
        after = [[0]*3  for j in range(2)]
        cur = [[0]*3  for j in range(2)]
        
        '''
        # base case 1 : cap=0
        for i in range(n-1,-1,-1):
            for j in range(2):                
                dp[i][j][0] = 0
        # base case 2 : 
        for j in range(2):
            for k in range(3):
                dp[n][j][k]=0
        '''

        for i in range(n-1,-1,-1):
            for j in range(2):
                for k in range(1,3): #cap=0, base case
                    if j==1:
                        cur[j][k]= max(-p[i]+ after[0][k], after[1][k])
                    else :
                        cur[j][k]=max(p[i]+ after[1][k-1], after[0][k])
            after = cur
        return cur[1][2]



        '''
        # memoisation
        # TC = O(n x cap x 2)
        # Space = O(n x cap x 2) + auxillary stack space
        dp=[[[-1]*3 for i in range(2)] for j in range(n)]
        return self.f(1,2,0,p,n,dp)
        '''



        


                    
