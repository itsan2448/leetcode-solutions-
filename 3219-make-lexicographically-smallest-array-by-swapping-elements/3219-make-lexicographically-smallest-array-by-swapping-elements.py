class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        grp=[] #list of q
        numToGrp={} # grps indexes

        for n in sorted(nums):
            if not grp or abs(n-grp[-1][-1])>limit:
                grp.append(deque())
            grp[-1].append(n)
            numToGrp[n]=len(grp)-1
            
        res=[]
        for n in nums:
            ind=numToGrp[n]
            res.append(grp[ind].popleft())
        return res