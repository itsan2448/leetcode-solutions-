class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        
        mb=0
        c=[] #events
        for i in nums:
            c.append((i-k,1))
            c.append((i+k+1,-1))
        c.sort()
        cSum=0
        for value,eff in c:
            cSum+=eff
            mb=max(mb,cSum)
        return mb


        
