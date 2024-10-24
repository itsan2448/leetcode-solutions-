class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        nei = collections.defaultdict(list) #adjaceny list .. patter->list(word)
        # collections.defaultdict(list) make sure initial list is empty
        wordList.append(beginWord)

        for word in wordList:
            for j in range(len(word)): 
                #start creating patterns
                pattern = word[:j] + "*" + word[j+1:]
                nei[pattern].append(word)

        vis=set([beginWord])
        q=deque([beginWord])
        ans=1

        while q:
            for i in range(len(q)):
                word=q.popleft()
                if word==endWord:
                    return ans
                for j in range(len(word)): 
                    #start creating patterns
                    pattern = word[:j] + "*" + word[j+1:]
                    for n in nei[pattern]:
                        if n not in vis:
                            vis.add(n)
                            q.append(n)
            ans+=1

        return 0

