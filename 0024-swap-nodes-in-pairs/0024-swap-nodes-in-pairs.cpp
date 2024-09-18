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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *dum=new ListNode(0);
        dum->next=head;
        ListNode *d=dum;

        while(head && head->next){
            ListNode *i=head,*j=head->next;

            i->next=j->next;
            j->next=i;
            d->next=j;
            d=i;            
            head=i->next;
        }
        return dum->next;
    }
};