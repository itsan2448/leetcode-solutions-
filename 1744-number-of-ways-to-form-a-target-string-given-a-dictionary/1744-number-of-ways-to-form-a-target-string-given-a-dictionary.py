class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        # O(w.k+t.k)
        mod = 10**9+7
        cnt = defaultdict(int) # (ind,char)->cnt of char in words
        for w in words:
            for ind,c in enumerate(w):
                cnt[(ind,c)]+=1
        dp = {}
        # i:index of target, k:ind of words[j][k]
        def dfs(i,k):
            if i==len(target):
                return 1 # target word built
            if k==len(words[0]):
                return 0 # not built
            if (i,k) in dp:
                return dp[(i,k)]
            
            c=target[i] # req character
            # on skip kth character
            skip = dfs(i,k+1)
            # include character
            inc = dfs(i+1,k+1)*cnt[(k,c)]
            dp[(i,k)]= (skip+inc)%mod
            return dp[(i,k)]
        
        return dfs(0,0)    