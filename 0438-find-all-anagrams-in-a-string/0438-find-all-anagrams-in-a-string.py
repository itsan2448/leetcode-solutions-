class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p)>len(s) :
            return []
        
        p_count = Counter(p)
        s_count = Counter(s[:len(p)])
        
        ans = []
        k = len(p)        
                
        if p_count == s_count:
            ans.append(0)

        for i in range(k,len(s)):
            s_count[s[i]] += 1
            s_count[s[i - k]] -= 1
            if s_count[s[i - k]] == 0:
                del s_count[s[i - k]]

            if p_count == s_count:
                ans.append(i-k+1)

        return ans
