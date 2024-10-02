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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *i=head;
        ListNode *d=new ListNode(0);
        ListNode *p=d;
        
        d->next=head;
        while(i){
            if(i->next && i->val==i->next->val){
                while(i->next && i->val==i->next->val){
                    i=i->next;
                }
                p->next=i->next;
            }else{
                p=p->next;                
            }           
            i=i->next;
        }
        return d->next;
    }
};