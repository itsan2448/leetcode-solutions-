/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right){        
        if(head==NULL || left==right) return head;
        ListNode* dum=new ListNode(0);
        dum->next=head;
        ListNode *leftprev=dum, *cur=head;
        int i;
        for(i=0;i<left-1;i++){
            leftprev=cur;
            cur=cur->next;
        }
        ListNode *prev=NULL;
        for(i=0;i<right-left+1;i++){
            ListNode *tmpnext = cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmpnext;
        }
        leftprev->next->next=cur;
        leftprev->next=prev;
        return dum->next;
    }
};