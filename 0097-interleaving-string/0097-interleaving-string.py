class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n,m=len(s1),len(s2)
        if n+m!=len(s3): 
            return 0
        dp=[[False]*(m+1) for i in range(n+1)]
        dp[n][m]=1 # when we have reached end of both the strings

        for i in range(n,-1,-1):
            for j in range(m,-1,-1):
                if i<n and s1[i]==s3[i+j] and dp[i+1][j]:
                    dp[i][j]=1
                if j<m and s2[j]==s3[i+j] and dp[i][j+1]:
                    dp[i][j]=1
                

        return dp[0][0]