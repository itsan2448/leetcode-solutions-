class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        ans=0
        n,m=len(grid),len(grid[0])

        def bfs(i,j):
            res=0
            q=deque()
            # vis={}
            q.append((i,j))
            # vis.add((i,j))
            dir=[(1,0),(-1,0),(0,1),(0,-1)]
            while q:
                a,b=q.popleft()
                res+=grid[a][b]
                grid[a][b]=0
                for r,c in dir:
                    if a+r>=0 and a+r<n and b+c>=0 and b+c<m and grid[a+r][b+c]>0:
                        q.append((a+r,b+c))

                        # vis.add(a+r,b+c)
            return res

        
        for i in range(n):
            for j in range(m):
                if grid[i][j]>0:
                    ans=max(ans,bfs(i,j))

        return ans