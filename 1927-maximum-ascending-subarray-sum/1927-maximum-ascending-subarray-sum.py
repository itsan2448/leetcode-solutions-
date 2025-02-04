class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        sm,ans=nums[0],nums[0]
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                sm+=nums[i]
            else:                
                sm=nums[i]
            ans=max(ans,sm)
        return max(ans,sm)
            