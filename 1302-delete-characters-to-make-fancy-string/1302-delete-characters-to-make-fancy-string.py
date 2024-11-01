class Solution:
    def makeFancyString(self, s: str) -> str:
        if len(s)<3:
            return s
        ans=""
        for i in s:
            if len(ans)>=2 and ans[-1]==i and ans[-2]==i:
                continue
            else:
                ans=ans+i
        return ans