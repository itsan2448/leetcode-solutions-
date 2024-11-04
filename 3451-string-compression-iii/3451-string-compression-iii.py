class Solution:
    # def add(self, word):

    def compressedString(self, word: str) -> str:
        ans=""
        
        i,j=0,0
        while j<len(word):            
            while j<len(word) and j-i<9 and word[i]==word[j]:                
                j+=1                
            ans += (str(j-i) + word[i])
            i=j                    
        return ans

            