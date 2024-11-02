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
    ListNode* findK(ListNode* cur, int k){
        while(cur!=NULL && k>0){
            cur=cur->next;
            k--;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dum = new ListNode(0);
        dum->next = head;
        ListNode* groupPrev = dum;
        while(1){
            ListNode *kth = findK(groupPrev,k);
            if(kth == NULL) break;
            ListNode *groupNext = kth->next;
            // reverse
            ListNode *prev = groupNext, *cur = groupPrev->next;
            while(cur!=groupNext){
                ListNode *tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            ListNode *tmp = groupPrev->next; // start of the reversed grp
            groupPrev->next = kth; // kth is the head of the reversed grp
            groupPrev = tmp; // tmp which is now the last node of the reversed group
        }
        return dum->next;
    }
};