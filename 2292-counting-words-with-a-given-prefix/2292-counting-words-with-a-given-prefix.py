class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        ans=0
        n=len(pref)
        for i in range(len(words)):
            if words[i][0:n]==pref:
                ans+=1
        return ans