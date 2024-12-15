# O(n+extraStudents⋅logn)
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        def gain(p,t):
            # the marginal gain
            return (p+1)/(t+1)-p/t
        mxheap=[] 
        # max heap of the current class sizes ordered by the change in pass ratio
        avg = 0
        n = len(classes)
        for i,j in classes:            
            heappush(mxheap,(-gain(i,j), i, j))
        
        while(extraStudents):
            a,b,c = heappop(mxheap)            
            heappush(mxheap,(-gain(b+1,c+1), b+1, c+1))
            extraStudents-=1
        for a,b,c in mxheap:
            avg += b/c
        return avg/len(classes)