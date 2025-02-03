class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        p,m,ans=0,0,0
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                p+=1
                m=0
            elif nums[i]<nums[i-1]:
                m+=1
                p=0
            else:
                p,m=0,0
            ans=max(ans,p,m)
        return ans+1