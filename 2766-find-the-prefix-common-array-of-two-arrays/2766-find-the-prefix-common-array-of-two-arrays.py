class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        l=len(A)
        ans=[0]*l
        seen=[0]*(l+1)
        common=0
        for i in range(l):
            if seen[A[i]]==0:
                seen[A[i]]=1
            elif seen[A[i]]==1:
                common+=1
            if seen[B[i]]==0:
                seen[B[i]]=1
            elif seen[B[i]]==1:
                common+=1
            ans[i]=common
        return ans