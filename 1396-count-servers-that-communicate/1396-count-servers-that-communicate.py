class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        
        m,n=len(grid),len(grid[0])
        r,c=[0]*m,[0]*n
        t=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    t+=1
                    r[i]+=1
                    c[j]+=1
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] and r[i]==1 and c[j]==1:
                    t-=1

        return t