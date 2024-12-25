# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        q = []
        if not root:
            return []
        q.append(root)
        ans = []
        while q:
            z=len(q)
            tmp = []
            while z:
                a=q.pop(0)
                if a.left:
                    q.append(a.left)
                if a.right:
                    q.append(a.right)
                tmp.append(a.val)
                z-=1
            ans.append(max(tmp))
        return ans              