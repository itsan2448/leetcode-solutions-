class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        pre=[]
        ans=[]
        vowels = {'a', 'e', 'i', 'o', 'u'}
        for i,x in enumerate(words):
            x = 1 if (x[0] in vowels and x[-1] in vowels) else 0
            if i>=1:
                pre.append(pre[i-1]+x)
            else:
                pre.append(x)

        for i,j in queries:
            if i==0:
                ans.append(pre[j])
            else:
                ans.append(pre[j]-pre[i-1])
        return ans