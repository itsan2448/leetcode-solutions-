class Solution:
    def check(self, nums: List[int]) -> bool:
        rot,n=0,len(nums)
        for i in range(n):
            if nums[i-1]>nums[i]:
                rot+=1
                if rot>1:
                    return False
        
        return True            