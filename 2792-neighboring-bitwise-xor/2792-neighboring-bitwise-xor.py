class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        first,last=0,0

        for n in derived:
            if n:
                last=~last
        
        return first==last