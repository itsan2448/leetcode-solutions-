/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*,Node*> old;
        old[NULL]=NULL;
        // copy the nodes
        Node* cur=head;
        while(cur){            
            old[cur]=new Node(cur->val);;
            cur=cur->next;
        }
        // link the links
        cur=head;
        while(cur){            
            Node *tmp=old[cur];
            tmp->next = old[cur->next];
            tmp->random = old[cur->random];
            cur=cur->next;
        }
        return old[head];
    }
};