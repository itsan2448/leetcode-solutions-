class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        
        n=len(nums)
        xorr = nums[0]
        for i in range(1,n):
            xorr = xorr^nums[i]
        
        maxxor = pow(2,maximumBit)-1

        res = []

        for i in range(n):
            res.append(xorr^maxxor)
            xorr = xorr^nums[-1-i]
        
        return res


