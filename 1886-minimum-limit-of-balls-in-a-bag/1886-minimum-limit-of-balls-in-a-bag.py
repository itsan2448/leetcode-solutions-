class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        
        l,r = 1,max(nums)
        res = 0
        
        def feasible (x):
            operations = 0
            for n in nums : 
                operations += math.ceil(n/x)-1
            return operations<=maxOperations

        while (l<=r):
            mid = l + (r-l)//2
            if feasible(mid):
                res = mid
                r = mid - 1
            else:
                l = mid + 1
            
        return res