class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        l,r = 1,max(quantities)
        res=0

        def viable(x):
            stores = 0
            for q in quantities:
                stores += math.ceil(q/x)
            return stores<=n 

        while l<=r:
            mid = l + (r-l)//2
            if viable(mid):
                res = mid
                r = mid - 1
            else :
                l = mid + 1

        return res
