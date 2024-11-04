class Solution:
    def maxProfit(self, p: List[int]) -> int:
        mn,pro=p[0],0
        for i in range(1,len(p)):
            pro=max(pro,p[i]-mn)
            mn=min(mn,p[i])
        return pro