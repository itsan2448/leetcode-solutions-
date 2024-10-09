class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m,n= len(grid),len(grid[0])
        time, fresh=0,0
        q=deque()
        for i in range(m):
            for j in range (n):
                if grid[i][j]==1:
                    fresh+=1 # add fresh oranges
                if grid[i][j]==2:
                    q.append([i,j])

        directions=[[0,1],[1,0],[0,-1],[-1,0]]
        while q and fresh>0:
            for i in range(len(q)):
                r,c=q.popleft()
                for dr,dc in directions:
                    row,col = r+dr,c+dc
                    if row>=0 and row<m and col>=0 and col<n and grid[row][col]==1:
                        grid[row][col]=2
                        q.append([row,col])
                        fresh-=1                    
            time+=1
        return time if fresh==0 else -1


