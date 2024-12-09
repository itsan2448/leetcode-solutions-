class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        # Step 1: Build the Prefix Array
        n = len(nums)
        pre = [0]*n
        for i in range(1,n):
            pre[i]=pre[i-1]
            if nums[i-1]%2==nums[i]%2:
                pre[i]+=1
        
        # Step 2: Process Queries
        ans = []
        for q in queries:
            l,r=q[0],q[1]
            s = pre[r]-pre[l] 
            ans.append(s==0)
        return ans