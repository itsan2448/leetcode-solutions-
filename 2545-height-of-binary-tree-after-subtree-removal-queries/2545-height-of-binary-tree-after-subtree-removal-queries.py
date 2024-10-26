# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    

    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        self.time = 0
        self.start, self.endd, self.depth = {}, {}, {} 
        
        def euler(root,dep):
            if not root:
                return
            self.start[root.val]=self.time            
            self.depth[self.time]=dep
            self.time+=1
            if root.left:
                euler(root.left,dep+1)
            if root.right:
                euler(root.right,dep+1)
            self.endd[root.val]=self.time

        euler(root,0)
        n=self.time
        pre,suf=[0]*(n+2),[0]*(n+2)
        pre, suf = [0] * (n + 2), [0] * (n + 2)
        for i in range(1, n + 1):
            pre[i] = max(self.depth.get(i - 1, 0), pre[i - 1])
        for i in range(n - 1, -1, -1):
            suf[i + 1] = max(self.depth.get(i, 0), suf[i + 2])
        ans=[]
        for q in queries:
            st=self.start[q]
            ed=self.endd[q]
            ans.append(max(pre[st],suf[ed+1]))
        return ans
