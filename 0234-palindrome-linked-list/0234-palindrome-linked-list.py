# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mid(self, head: Optional[ListNode]):
        slow,fast = head, head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        return slow
    
    def reverse(self, head: Optional[ListNode]):
        prev,cur = None, head
        while cur:
            tmp = cur.next
            cur.next=prev
            prev=cur
            cur=tmp
        return prev

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        md = self.mid(head)
        last = self.reverse(md)
        cur = head
        cur2 = last
        while cur!=md:
            if cur.val!=cur2.val:
                return False
            cur=cur.next
            cur2=cur2.next
        
        return True

