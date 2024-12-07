class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l,r = 1,max(piles)
        res = 0
        def feasible (x):
            operations = 0
            for n in piles : 
                operations += math.ceil(n/x)
            return operations<=h
        while (l<=r):
            mid = l + (r-l)//2
            if feasible(mid):
                res = mid
                r = mid - 1
            else:
                l = mid + 1    
        return res