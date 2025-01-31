class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n=len(grid)

        def outOfBounds(r,c):
            return (r>=n or c>=n or r<0 or c<0)
                
        def dfs(r,c,lab):
            if outOfBounds(r,c) or grid[r][c]!=1:
                return 0
            grid[r][c]=lab
            size=1
            nei=[[r+1,c],[r-1,c],[r,c+1],[r,c-1]]
            for nr,nc in nei:
                size+=dfs(nr,nc,lab)
            return size

        def connect(r,c):
            vis=set()
            res=1
            nei=[[r+1,c],[r-1,c],[r,c+1],[r,c-1]]
            for nr,nc in nei:    
                if not outOfBounds(nr,nc) and grid[nr][nc] not in vis:
                    res+=size[grid[nr][nc]]
                    vis.add(grid[nr][nc])
            return res

        # 1. precomputing areas
        size=defaultdict(int) #islandLabel->size
        label=2
        for r in range(n):
            for c in range(n):
                if grid[r][c]==1:
                    size[label]=dfs(r,c,label)        
                    label+=1

        # 2. flipping water
        res=0 if not size else max(size.values())
        for r in range(n):
            for c in range(n):
                if grid[r][c]==0:
                    res=max(res,connect(r,c))
        
        return res