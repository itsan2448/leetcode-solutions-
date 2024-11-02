class Trie:
    def __init__(self):
        self.children={}
        self.isend=False
    def addWord(self,word):
        cur=self
        for c in word:
            if c not in cur.children:
                cur.children[c]=Trie()
            cur=cur.children[c]
        cur.isend=True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = Trie()
        for w in words:
            root.addWord(w)
        i,j=len(board),len(board[0])
        res,vis=set(),set()

        def dfs(x,y,node,word):
            if(x<0 or y<0 or x>=i or y>=j or board[x][y] not in node.children or (x,y) in vis):
                return 
            vis.add((x,y))
            node = node.children[board[x][y]]
            word+=board[x][y]
            if node.isend :
                res.add(word)            
            
            dir = [(1,0),(-1,0),(0,1),(0,-1)]
            for a,b in dir:
                dfs(x+a, y+b, node, word)
            
            vis.remove((x,y))
        
        for r in range(i):
            for c in range(j):
                dfs(r,c,root,"")
        
        return list(res)

        