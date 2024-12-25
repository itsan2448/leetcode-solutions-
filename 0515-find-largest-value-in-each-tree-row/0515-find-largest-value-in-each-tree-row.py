# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        
        if not root:
            return []
        q = []
        q.append(root)
        ans = []
        while q:
            z=len(q)
            mx = float("-inf")
            while z:
                a=q.pop(0)
                if a.left:
                    q.append(a.left)
                if a.right:
                    q.append(a.right)
                if mx<a.val:
                    mx=a.val
                z-=1
            ans.append(mx)
        return ans              