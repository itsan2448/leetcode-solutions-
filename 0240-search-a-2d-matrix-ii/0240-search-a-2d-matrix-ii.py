class Solution:
    def searchMatrix(self, x: List[List[int]], t: int) -> bool:
        m,n=len(x),len(x[0])
        r=0
        while r<m and n>0:
            c=x[r][n-1]
            if c==t:
                return True
            if c>t:
                # ignore last clm
                n-=1
            if c<t:
                # eliminate the entire rth row
                r+=1
        return False
