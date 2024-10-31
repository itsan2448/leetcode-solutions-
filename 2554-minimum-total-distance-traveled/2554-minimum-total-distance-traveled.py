class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        f=[]
        for i in factory:
            for j in range(i[1]):
                f.append(i[0])
        n,m=len(robot),len(f)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(0,m+1):
            dp[0][i]=0 # No robots require zero distance
        for i in range(1,n+1):
            dp[i][0]=float('inf') # no factories require infinity distance
        
        for i in range(1,n+1):
            for j in range (1,m+1):
                pick= abs(f[j-1]-robot[i-1]) + dp[i-1][j-1]
                notpick = dp[i][j-1]
                dp[i][j]=min(pick,notpick)
        return dp[n][m]
