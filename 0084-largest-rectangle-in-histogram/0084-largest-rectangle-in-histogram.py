class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # T.C. - O(n)
        # S.C. - O(n)
        stack=[] #(ind,hei)
        ans=0
        for i,h in enumerate(heights):
            start=i
            while stack and stack[-1][1]>h:
                ind,hei = stack.pop()
                ans=max(ans,(i-ind)*hei)
                start=ind # we can extend start ind backwards
            stack.append((start,h))
                                        
        for i,h in stack:
            ans=max(ans,h*(len(heights)-i))
        return ans                                 