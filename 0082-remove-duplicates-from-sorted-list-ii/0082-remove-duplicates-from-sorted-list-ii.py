# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dum=ListNode(0)
        i=head
        p=dum
        dum.next=head
        
        while i:
            if i.next and i.next.val==i.val:
                while i.next and i.next.val==i.val:
                    i.next=i.next.next
                p.next=i.next
            else:
                p=p.next
            i=i.next

        return dum.next
