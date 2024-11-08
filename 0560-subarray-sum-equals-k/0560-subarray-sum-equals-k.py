class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res =0
        preSum = {0:1} # base case
        curSum = 0
        n = len(nums)
        for i in nums:  
            curSum += i      
            res += preSum.get(curSum-k,0)    
            preSum[curSum] = 1 + preSum.get(curSum,0)
        return res
