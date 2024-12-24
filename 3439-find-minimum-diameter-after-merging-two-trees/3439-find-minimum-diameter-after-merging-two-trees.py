class Solution:
    def minimumDiameterAfterMerge(self,e1:List[List[int]],e2:List[List[int]])->int:
        n = len(e1)
        m = len(e2)
        def build_adj(e):
            adj = defaultdict(list)
            for n1,n2 in e:
                adj[n1].append(n2)
                adj[n2].append(n1)
            return adj
        adj1=build_adj(e1)
        adj2=build_adj(e2)
        # dfs
        # return [dia, max leaf path]
        def dia(cur,par,adj):
            maxD=0
            maxChildPath=[0,0] # heap
            for nei in adj[cur]:
                if nei==par:
                    continue
                neiD,neiMaxLeafPath = dia(nei,cur,adj)
                maxD=max(maxD,neiD)

                heappush(maxChildPath,neiMaxLeafPath)
                heappop(maxChildPath)
            maxD=max(maxD,sum(maxChildPath))                
            return [maxD,max(maxChildPath)+1]

        d1,_=dia(0,-1,adj1)
        d2,_=dia(0,-1,adj2)
        return max(d1,d2,ceil(d1/2)+ceil(d2/2)+1)