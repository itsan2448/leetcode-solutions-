# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # BFS
        q=deque()
        q.append(root)
        r = False # reversed=0
        while q:
            x=len(q)
            arr=[] # arr for TreeNode* for later swapping val on odd level
            for i in range(x):
                n = q.popleft()
                if n.left:
                    q.append(n.left)
                if n.right:
                    q.append(n.right)
                if r:
                    arr.append(n)
                    if i>=x/2:
                        arr[i].val,arr[x-1-i].val=arr[x-1-i].val,arr[i].val
            r = not r
        return root