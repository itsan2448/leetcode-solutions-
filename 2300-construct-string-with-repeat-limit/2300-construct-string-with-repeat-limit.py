class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        fq = Counter(s) #Frequency Counting
        pq = [(-ord(char),count) for char, count in fq.items()] #Max-Heap
        heapify(pq)
        res = []
        while pq:
            char,cnt=heappop(pq) #current largest            
            used = min(repeatLimit,cnt)
            res.append(chr(-char)*used) 
            cnt-=used
            if cnt>0:
                if not pq: #no second largest character available
                    break
                nxtCh,nxtCnt=heappop(pq) #second largest
                res.append(chr(-nxtCh))
                nxtCnt-=1

                if nxtCnt>0: 
                    heappush(pq,(nxtCh,nxtCnt)) #push back second largest
                heappush(pq,(char,cnt)) #push back largest
        return "".join(res)