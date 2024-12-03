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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dum = new ListNode(0);
        unordered_set<int> s(nums.begin(),nums.end());        
        dum->next=head;
        ListNode* p=dum;
        ListNode* i=head;
        while(i!=NULL){
            if(s.find(i->val)!=s.end())
                p->next=i->next;                
            else
                p=i;    
            i=i->next;
        }
        return dum->next;
    }
};