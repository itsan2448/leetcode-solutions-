class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        pdtCnt=defaultdict(int) #n1*n2->count
        pairCnt=defaultdict(int) #n1*n2->count of pairs (a,b),(c,d)

        n=len(nums)
        for i in range(n):
            for j in range(i+1,n):
                pdt = nums[i]*nums[j]
                pairCnt[pdt]+=pdtCnt[pdt]
                pdtCnt[pdt]+=1

        res=0
        for c in pdtCnt.values():
            pairs=(c*(c-1))//2
            res+=pairs*8
        return res