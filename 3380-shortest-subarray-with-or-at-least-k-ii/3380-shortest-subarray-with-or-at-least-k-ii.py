class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        res=float("inf")
        bits=[0]*32

        def update_bits(bits, num, dif):
            for i in range(32):
                if num&(1<<i):
                    bits[i]+=dif

        def bitsToInt(bits):
            res = 0
            for i in range(32):
                if bits[i]:
                    res += (1<<i)
            return res

        l=0
            
        for r in range(len(nums)):
            update_bits(bits,nums[r],1)
            curor = bitsToInt(bits)
            
            while l<=r and curor>=k:
                res = min(res, r-l+1)                
                update_bits(bits,nums[l],-1)
                curor=bitsToInt(bits)
                l+=1

        return -1 if res==float("inf") else res



