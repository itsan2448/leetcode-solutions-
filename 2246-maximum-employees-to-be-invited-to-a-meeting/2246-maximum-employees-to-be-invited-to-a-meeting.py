class Solution:
    def maximumInvitations(self, f: List[int]) -> int:
        n=len(f)
        vis=[False]*n
        longestCycle=0
        len2cycles=[]
        for i in range(n):
            if vis[i]:
                continue            
            start,cur=i,i
            curSet=set()
            while not vis[cur]:
                vis[cur]=True
                curSet.add(cur)
                cur=f[cur]
            
            if cur in curSet:
                l=len(curSet)
                while start!=cur:
                    l-=1
                    start=f[start]
                longestCycle=max(longestCycle,l)
                if l==2:
                    len2cycles.append([cur,f[cur]])
        
        inverted=defaultdict(list)
        for dst,src in enumerate(f):
            inverted[src].append(dst)


        def bfs(src,p):
            q=deque([(src,0)]) #node,length
            mxl=0
            while q:
                n,l=q.popleft()
                if n==p:
                    continue
                mxl=max(l,mxl)
                for nei in inverted[n]:
                    q.append((nei,l+1))
            return mxl


        chainSum=0

        for a,b in len2cycles:
            chainSum+=bfs(a,b)+bfs(b,a)+2        

        return max(chainSum,longestCycle)