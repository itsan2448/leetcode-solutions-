class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # Step 1 : Sort
        events.sort()
        n=len(events)
        # Step 2 : suffix array
        suffixMax=[0]*n
        suffixMax[-1]=events[-1][2] # last event
        # Step 3 : fill sufmax
        for i in range(n-2,-1,-1):
            suffixMax[i]=max(events[i][2],suffixMax[i+1])
        ans=0
        for i in range(n):
            l,r=i+1,n-1
            nxt=-1
        # Step 4 : binary search to find the next non-overlapping event
            while l<=r :
                mid = l + (r-l)//2
                if events[mid][0]>events[i][1]:
                    nxt = mid
                    r = mid - 1
                else :
                    l = mid + 1
        # Step 5 : when valid event is found
            if nxt!=-1:
                ans=max(ans,events[i][2]+suffixMax[nxt])
            ans = max(ans,events[i][2])
        return ans
