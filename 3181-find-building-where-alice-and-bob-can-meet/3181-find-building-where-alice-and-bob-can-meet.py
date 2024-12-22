class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:       
        n = len(heights)
        ans = [-1]*len(queries)

        grp = defaultdict(list) # r=> [(max height, query index)]

        for i,(x,y) in enumerate(queries):
            if x>y:
                x,y=y,x
            if x==y or heights[x]<heights[y]:
                ans[i] = y
                # clear cut answer
            else:
                h = max(heights[x],heights[y])
                grp[y].append((h,i))
            
        min_heap = []
        for i,h in enumerate(heights):
            for qh,qi in grp[i]:
                heapq.heappush(min_heap, (qh,qi))
            while min_heap and h>min_heap[0][0]:
                qh,qi=heapq.heappop(min_heap)
                ans[qi]=i 
            
        # new_q = [[] for _ in range(n)]
        # mono = [] # leftmost valid building
        # for i,(x,y) in enumerate(queries):
        #     if x>y:
        #         x,y=y,x
        #     if x==y or heights[x]<heights[y]:
        #         ans[i] = y
        #         continue
        #     for j in range(y+1,n):
        #         if heights[j] > max(heights[x],heights[y]):
        #             ans[i]=j
        #             break
        return ans