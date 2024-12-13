class Solution:
    def findScore(self, nums: List[int]) -> int:
        score = 0
        n = len(nums)
        mark = [False] * n 
        pq = [(num,i) for i,num in enumerate(nums)]
        heapify(pq)
        while pq:
            smallest,idx = heappop(pq)            
            if not mark[idx]:                
                if idx-1>=0:
                    mark[idx-1]=True
                if idx+1<len(nums):
                    mark[idx+1]=True
                score += smallest
        return score