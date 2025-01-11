class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s)<k:
            return False
        if k==len(s):
            return True
        count=Counter(s)
        odd=sum(f%2==1 for f in count.values())
        return odd<=k   