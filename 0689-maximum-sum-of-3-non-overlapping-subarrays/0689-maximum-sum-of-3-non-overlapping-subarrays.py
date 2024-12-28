class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        kSum=[sum(nums[:k])]

        for i in range(k,len(nums)):
            prev=kSum[-1]
            kSum.append(prev-nums[i-k]+nums[i])
        
        dp = {}

        def getMaxSum(i,cnt):
            if cnt==3 or i>len(nums)-k:
                return 0
            if (i,cnt) in dp:
                return dp[(i,cnt)]
            # include
            include = kSum[i]+getMaxSum(i+k,cnt+1)
            # exclude
            exclude = getMaxSum(i+1,cnt)
            dp[(i,cnt)] = max(include,exclude)
            return dp[(i,cnt)]        

        def getIndices():
            indices=[]
            i=0
            while i<=len(nums)-k and len(indices)<3:
                include = kSum[i] + getMaxSum(i+k,len(indices)+1)
                exclude = getMaxSum(i+1,len(indices))
                if include>=exclude:
                    indices.append(i)
                    i+=k
                else:
                    i+=1
            return indices
        
        return getIndices()