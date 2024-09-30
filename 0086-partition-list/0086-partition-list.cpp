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
    ListNode* partition(ListNode* head, int x) {

        ListNode* s=new ListNode(-1);
        ListNode* l=new ListNode(-1);
        ListNode* i=head;
        ListNode* first=s,*last=l;
        while(i!=NULL){
            if(i->val<x){
                s->next=i;
                s=s->next;
            }else{
                l->next=i;
                l=l->next;
            }
            i=i->next;
        }
        l->next=NULL;
        s->next=last->next;
        return first->next;
    }
};