class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        def count_bits(n):
        #     res=0
        #     while n:
        #         res+=n&1
        #         n=n>>1
            # return res
            return bin(n).count("1")
        
        cur_min,cur_max = nums[0],nums[0]
        prev_max = float("-inf")

        for n in nums:
            if count_bits(n) == count_bits(cur_min):
                cur_min,cur_max = min(cur_min,n),max(cur_max,n)
            else: # new subarray
                if cur_min < prev_max :
                    return False
                prev_max=cur_max
                cur_min,cur_max=n,n
        
        return not (cur_min < prev_max)
        # return True



