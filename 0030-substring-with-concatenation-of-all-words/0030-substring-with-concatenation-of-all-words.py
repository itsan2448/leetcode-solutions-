class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans=[]
        if not words or not s:
            return ans
        wl = len(words[0]) # length of each word
        l = len(words) # no. of words
        f={} # dictinory to store words 
        for i in words:
            f[i]= f.get(i,0)+1

        for i in range(wl):
            seen={}
            left,count=i,0
            for right in range(i,len(s)-wl+1,wl):
                w=s[right:right+wl]
                if w in f:
                    seen[w]= seen.get(w,0)+1                  
                    count+=1
                    while seen[w]>f[w]:
                        a=s[left:left+wl]
                        seen[a]-=1
                        count-=1
                        left+=wl
                    if count==l:
                        ans.append(left)
                else:
                    seen.clear()
                    count=0
                    left=right+wl
        return ans
