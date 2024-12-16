class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        heap=[]
        for i,num in enumerate(nums):
            heappush(heap,(num,i))
        while k:
            num,i = heappop(heap)
            num*=multiplier
            nums[i]=num
            heappush(heap,(num,i))
            k-=1
        return nums