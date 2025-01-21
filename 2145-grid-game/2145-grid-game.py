class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        minAns=float("inf")
        r1,r2=sum(grid[0]),0

        for i in range(len(grid[0])):
            r1-=grid[0][i]
            minAns=min(minAns,max(r1,r2))
            r2+=grid[1][i]

        return minAns