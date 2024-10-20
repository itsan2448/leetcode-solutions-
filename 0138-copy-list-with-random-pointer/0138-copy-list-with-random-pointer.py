"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        cur=head
        old={None:None}

        while cur:
            tmp=Node(cur.val)
            old[cur]=tmp
            cur=cur.next
        
        cur=head
        while cur:
            tmp=old[cur]
            tmp.next = old[cur.next]
            tmp.random = old[cur.random]
            cur=cur.next
        
        return old[head]