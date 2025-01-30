class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        adj=defaultdict(list)
        for a,b in edges:
            adj[a].append(b)
            adj[b].append(a)

        def getConnectedComp(src):
            q=deque([src])
            comp=set([src])
            while q:
                n=q.popleft()
                for nei in adj[n]:
                    if nei in comp:                        
                        continue
                    q.append(nei)
                    comp.add(nei)
                    visit.add(nei)
            return comp

        def longestPath(src):
            q=deque([(src,1)]) # (node,grp)
            dist={src:1} # node-> length from src + 1
            while q:
                n,l=q.popleft()
                for nei in adj[n]:
                    if nei in dist:
                        if dist[nei]==l:
                            return -1
                        continue
                    q.append((nei,l+1))
                    dist[nei]=l+1
            return max(dist.values())

        visit=set()
        res=0
        for i in range(1,1+n):
            if i in visit:
                continue
            visit.add(i)
            comp=getConnectedComp(i)            
            mx=0
            for src in comp:
                l=longestPath(src)
                if l==-1:
                    return -1
                mx=max(mx,l)
            res+=mx

        return res