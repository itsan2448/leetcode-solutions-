class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        n=len(nums)
        if n==1:
            return True
        for i in range(1,n):
            if (nums[i-1]+nums[i])%2==0:
                return False
        return True

        # return all((x^y)&1 for x,y in zip(nums,nums[1:]))