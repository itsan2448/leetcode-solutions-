class Solution:
    def canTransform(self, start: str, target: str) -> bool:
        n=len(start)
        i,j=0,0
        start+='@' #add stoppers
        target+='@'
        while i<n or j<n :
            while i<n and start[i]=='X':
                i+=1
            while j<n and target[j]=='X':
                j+=1
            
            if start[i]!=target[j] or (start[i]=='L' and i<j) or (start[i]=='R' and i>j):
                return False
            i+=1
            j+=1
        return True