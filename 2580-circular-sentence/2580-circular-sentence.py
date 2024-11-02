class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        if sentence[0]!=sentence[-1] :
            return False
        l=sentence.split(" ")
        for i in range(len(l)-1):
            if l[i][-1]!=l[i+1][0]:
                return False
        return True
