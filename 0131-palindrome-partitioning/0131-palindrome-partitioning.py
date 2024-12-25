class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def pal(s):
            # string ==reverse string
            return s==s[::-1]
            
        def backtrack(i,path):
            if i==len(s):
                ans.append(path[:])  #shallow copy
                return
            # all possible partitions
            for j in range(i+1,len(s)+1):
                if pal(s[i:j]):
                    backtrack(j,path+[s[i:j]])
        ans = []
        backtrack(0,[])
        return ans