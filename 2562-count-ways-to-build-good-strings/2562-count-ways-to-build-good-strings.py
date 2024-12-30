class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        mod=10**9+7
        dp={}
        dp[0] = 1
        for i in range(1,high+1):
            dp[i]=(dp.get(i-one,0)+dp.get(i-zero,0))%mod
        return sum([dp[i] for i in range(low,high+1)])%mod

        def dfs(length):
            if length>high:
                return 0
            if length in dp:
                return dp[length]
            dp[length] = 1 if length>=low else 0
            dp[length] += dfs(length+zero)+dfs(length+one)
            dp[length]%=mod
            return dp[length]
        return dfs(0)