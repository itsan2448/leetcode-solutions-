class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # memoisation code
        cache = {}
        def dfs(i,j):
            if (i,j) in cache:
                return cache[(i,j)]

            if i>=len(s) and j>=len(p):
                return True
            if j>=len(p):
                return False

            match = (i<len(s) and (s[i]==p[j] or p[j]=='.'))

            if (j+1)<len(p) and p[j+1]=='*':
                cache[(i,j)] = ((match and dfs(i+1,j)) or dfs(i,j+2))
                return cache[(i,j)]
            # use a*
            # not use a*
            if match :
                cache[(i,j)] = dfs(i+1,j+1)
                return cache[(i,j)]
            cache[(i,j)] = False
            return False

        return dfs(0,0)


        '''
        # tabulation code

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
        '''