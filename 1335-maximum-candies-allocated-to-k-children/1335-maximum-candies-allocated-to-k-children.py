class Solution:
    def maximumCandies(self, candies: List[int], h: int) -> int:
        # O(log(max(candies)))
        if not candies:
            return 0
        l,r = 1,max(candies)
        res = 0
        def feasible (x):
            customers = 0
            for c in candies : 
                customers += (c//x)
            return customers>=h

        while (l<=r):
            mid = l + (r-l)//2
            if feasible(mid):
                res = mid
                l = mid + 1
            else:                 
                r = mid - 1   
        return res