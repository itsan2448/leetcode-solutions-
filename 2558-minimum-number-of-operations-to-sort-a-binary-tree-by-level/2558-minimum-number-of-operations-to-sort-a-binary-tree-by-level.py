# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        q=deque([root])        
        ans=0        
        while q:
            z= len(q)
            idx = list(range(z))
            tmp = [0]*z
            for i in range(z):
                node = q.popleft()  
                tmp[i]=node.val              
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            idx.sort(key=lambda i: tmp[i])
            i=0
            while i<z:
                j=idx[i]
                if j!=i:
                    ans+=1
                    idx[i],idx[j]=idx[j],idx[i]
                else:
                    i+=1
        return ans