class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        c,i,sum=0,1,0
        s= {x for x in banned if x<=n}
        # while (i<=n and sum+i<=maxSum):
        #     if i not in s:
        #         sum+=i
        #         c+=1
        #     i+=1
        for i in range(1,n+1):
            if i in s:
                continue
            sum+=i
            if sum>maxSum:
                break
            c+=1
        return c
