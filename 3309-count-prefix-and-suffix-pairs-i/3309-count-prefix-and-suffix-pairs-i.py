class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans=0
        n=len(words)
        for i in range(n):
            for j in range(i+1,n):
                z=len(words[i])
                s=len(words[j])
                if s>=z:
                    pre=words[j][0:z]
                    suf=words[j][-z:]
                    # print(pre)
                    # print(suf)
                    if words[i]==pre and words[i]==suf:
                        ans+=1
                else:
                    continue
        return ans