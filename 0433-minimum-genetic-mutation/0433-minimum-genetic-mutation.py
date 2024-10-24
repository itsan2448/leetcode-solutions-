class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if endGene not in bank:
            return -1
        nei = collections.defaultdict(list) #adjaceny list .. patter->list(word)
        # collections.defaultdict(list) make sure initial list is empty
        bank.append(startGene)

        for word in bank:
            for j in range(len(word)): 
                #start creating patterns
                pattern = word[:j] + "*" + word[j+1:]
                nei[pattern].append(word)

        vis=set([startGene])
        q=deque([startGene])
        ans=0

        while q:
            for i in range(len(q)):
                word=q.popleft()
                if word==endGene:
                    return ans
                for j in range(len(word)): 
                    #start creating patterns
                    pattern = word[:j] + "*" + word[j+1:]
                    for n in nei[pattern]:
                        if n not in vis:
                            vis.add(n)
                            q.append(n)
            ans+=1

        return -1