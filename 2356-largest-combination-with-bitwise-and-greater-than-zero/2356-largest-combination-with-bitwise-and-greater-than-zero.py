class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        ans = 0
        for i in range(32):
            cnt = 0
            for n in candidates:
                cnt += 1 if (n & 1<<i) else 0
            ans = max(ans, cnt)
        
        return ans