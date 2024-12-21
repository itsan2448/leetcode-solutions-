class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = defaultdict(list)
        for n1,n2 in edges:
            adj[n1].append(n2)
            adj[n2].append(n1)
        res=0
        def dfs(n,par):
            total=values[n]
            for child in adj[n]:
                if child!=par:
                    total+=dfs(child,n)
            if total%k==0:
                nonlocal res 
                res+=1
            return total
        dfs(0,-1)
        return res