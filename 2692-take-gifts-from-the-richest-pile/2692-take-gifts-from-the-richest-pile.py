class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-x for x in gifts]
        heapify(gifts)
        i=0
        for _ in range(k):
            largest = -heappop(gifts) 
            if largest == 1: 
                heappush(gifts, -largest)
                break
            heappush(gifts, -isqrt(largest))

        return -sum(gifts)