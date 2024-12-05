class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if s==None or p==None:
            return False

        n,m=len(s),len(p)
        dp = [[False] * (m+1) for _ in range(n+1)]
        dp[0][0] = True # base case

        for i in range(0,m):
            if p[i]=='*' and dp[0][i-1]:
                dp[0][i+1]=True

        for i in range(n):
            for j in range(m):
                if p[j]==s[i] or p[j]=='.':
                    dp[i+1][j+1]=dp[i][j]                
                if p[j]=='*':
                    if p[j-1]!=s[i] and p[j-1]!='.':
                        dp[i+1][j+1]=dp[i+1][j-1] # a* only counts as empty
                    else:
                        # a* counts as multiple a
                        # a* counts as single a
                        # a* counts as empty
                        dp[i+1][j+1] = dp[i][j+1] | dp[i+1][j] | dp[i+1][j-1]

        return dp[n][m]