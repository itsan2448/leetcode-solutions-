class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        pre=[]
        pre.append(nums[0])
        for i in range(1,len(nums)):
            pre.append(pre[-1]+nums[i])
        ans=0
        for i in range(len(pre)-1):
            ans+= 1 if pre[i]>=pre[-1]-pre[i] else 0
        return ans