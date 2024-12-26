class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # # memoisation
        # dp = {} # (idx,cur_sum)->no. of ways
        # def backtrack(idx,sum): 
        #     if (idx,sum) in dp:
        #         return dp[(idx,sum)]
        #     if idx==len(nums):
        #         return 1 if sum==target else 0
        #     dp[(idx,sum)] = (backtrack(idx+1,sum+nums[idx])+backtrack(idx+1,sum-nums[idx]))
        #     return dp[(idx,sum)]
        # return backtrack(0,0)

        # O(n*sum(nums))

        # bottomUp
        n=len(nums)
        dp = [defaultdict(int) for i in range(n+1)]
        dp[0][0]=1 # (0 element, 0 sum)-> 1 way to achieve 
        for i in range(n):
            for sum,count in dp[i].items():
                dp[i+1][sum + nums[i]] += count
                dp[i+1][sum - nums[i]] += count
        return dp[len(nums)][target]

