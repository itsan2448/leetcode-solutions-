class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n=len(graph)
        ind=[0]*n
        adj=[[] for _ in range(n)]

        for i in range(n):
            for nei in graph[i]:
                adj[nei].append(i)
                ind[i]+=1
        
        q=deque()
        for i in range(n):
            if ind[i]==0:
                q.append(i)
        
        safe = [False]*n
        while q:
            node=q.popleft()
            safe[node]=True

            for nei in adj[node]:
                ind[nei]-=1
                if ind[nei]==0:
                    q.append(nei)

        ans=[]

        for i in range(n):
            if safe[i]:
                ans.append(i)
        
        return ans
