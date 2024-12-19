class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n,s,sortS=len(arr),0,0        
        ans = 0

        for i in range(n):
            s+=arr[i] #prefixsum
            sortS+=i #prefixsum od sorted array
            if s==sortS:
                ans+=1 #chunks
        return ans
            