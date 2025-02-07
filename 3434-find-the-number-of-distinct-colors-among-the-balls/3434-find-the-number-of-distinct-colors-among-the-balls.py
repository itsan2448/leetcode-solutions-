class Solution:
    def queryResults(self, l: int, q: List[List[int]]) -> List[int]:
        ball,col,ans={},{},[]
        dis=0
        for i,v in q:
            if i in ball:
                col[ball[i]]-=1
                if col[ball[i]]==0:
                    dis-=1
            ball[i]=v
            col[v]=col.get(v,0)+1
            if col[v]==1: 
                dis+=1
            ans.append(dis)
        return ans