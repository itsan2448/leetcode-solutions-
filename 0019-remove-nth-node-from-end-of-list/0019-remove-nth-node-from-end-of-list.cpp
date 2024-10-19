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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *d=new ListNode(0);
        d->next=head; 
        ListNode *l=d,*r=head;
               
        int c=0; 
        while(n>0 && r!=NULL){
            r=r->next;
            n--;
        }
        while(r!=NULL){
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;
        return d->next;
    }    
};