class Solution:
    def maxProfit(self, p: List[int], fee: int) -> int:
        n = len(p)
         
        aheadBuy, aheadNotBuy = 0,0

        for i in range (n-1,-1,-1): 
            curNotBuy = max(p[i]+aheadBuy-fee,aheadNotBuy)
            curBuy = max(-p[i]+aheadNotBuy,aheadBuy)
            
            aheadBuy, aheadNotBuy=curBuy, curNotBuy 
            

        return curBuy