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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        ListNode* i=head;
        int n=1;
        while(i->next){
            i=i->next;
            n++;
        }
        k%=n;
        if(k==0) return head;

        i->next=head;
        i=head;
        ListNode* p=NULL;
        for(int j=0;j<n-k;j++){
            p=i;
            i=i->next;
        }
        p->next=nullptr;
        return i;
    }
};