class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        row, clm=len(mat),len(mat[0])
        pos={mat[r][c]:(r,c) for r in range(row) for c in range(clm)}
        r_count=[clm]*row
        c_count=[row]*clm
        for i,v in enumerate(arr):
            r,c=pos[v]
            r_count[r]-=1
            c_count[c]-=1
            if r_count[r]==0 or c_count[c]==0:
                return i
        return -1