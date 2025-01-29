class Solution:
    def findRedundantConnection(self, g: List[List[int]]) -> List[int]:
        N=len(g)
        par=[i for i in range(N+1)]
        rank=[1]*(N+1)

        def find(n):
            if n!=par[n]:
                par[n]=find(par[n])
            return par[n]

        def union(a,b):
            p,q=find(a),find(b)
            if p==q:
                return False
            if rank[p]>rank[q]:
                par[q]=p
                rank[p]+=rank[q]
            else :
                par[p]=q
                rank[q]+=rank[p]
            return True

        for n1,n2 in g:
            if not union(n1,n2):
                return [n1,n2]