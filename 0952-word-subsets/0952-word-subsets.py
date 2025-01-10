class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        ans=[]
        maxF=[0]*26
        tmpF=[0]*26

        for w in words2:
            for c in w:
                tmpF[ord(c)-ord('a')]+=1
            for i in range(26):
                maxF[i]=max(maxF[i],tmpF[i])
            tmpF=[0]*26
        
        for w in words1:
            for c in w:
                tmpF[ord(c)-ord('a')]+=1
            flag=True
            for i in range(26):
                if maxF[i]>tmpF[i]:
                    flag=False
                    break
            if flag:
                ans.append(w)
            tmpF=[0]*26
        return ans