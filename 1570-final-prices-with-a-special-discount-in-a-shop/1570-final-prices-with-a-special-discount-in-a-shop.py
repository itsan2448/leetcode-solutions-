class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n=len(prices)
        for i in range(n):
            j = i+1
            while j<n and prices[j]>prices[i] :
                j+=1    
            if j<n and prices[j]<=prices[i]:         
                prices[i]-=prices[j]         
        return prices