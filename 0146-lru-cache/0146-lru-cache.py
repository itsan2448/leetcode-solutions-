class node:
    def __init__(self,key,val):
        self.key,self.val=key,val
        self.prev=self.next=None
class LRUCache:

    def __init__(self, capacity: int):
        self.cap=capacity
        self.cache={} # hashmap key->nodes
        self.left,self.right=node(0,0),node(0,0) 
        # LRU and most recent nodes
        self.left.next,self.right.prev = self.right,self.left
    
    # remove from list
    def remove (self,node):
        prev,nxt=node.prev,node.next
        prev.next,nxt.prev= nxt,prev

    # insert at right
    def insert (self,node):
        prev,nxt= self.right.prev,self.right
        prev.next=nxt.prev=node
        node.prev,node.next=prev,nxt

    def get(self, key: int) -> int:
        if key in self.cache:
            # to do - update most recent
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, val: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key]=node(key,val)
        self.insert(self.cache[key])
        if len(self.cache)>self.cap:
            # remove LRU
            lru=self.left.next
            self.remove(lru)
            del self.cache[lru.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)