class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n=len(nums)
        ans=0
        st=[] #monotonic stack
        for i in range(len(nums)):
            if not st or nums[i]<nums[st[-1]]:
                st.append(i)
        for i in range(n-1,-1,-1):
            while st and nums[st[-1]]<=nums[i]: #valid ramp
                ans=max(ans,i-st.pop())
        return ans
