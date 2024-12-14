class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        l,ans = 0,0
        mn,mx=deque(),deque() #store idx
        for r in range(len(nums)):
            while mn and nums[mn[-1]]>=nums[r]:
                mn.pop()
            while mx and nums[mx[-1]]<=nums[r]:
                mx.pop()
            mn.append(r)
            mx.append(r)
            while nums[mx[0]]-nums[mn[0]]>2:
                l+=1
                if mn[0]<l:mn.popleft()
                if mx[0]<l:mx.popleft()
            ans+=(r-l)+1
        return ans