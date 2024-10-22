/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* node,map<Node*,Node*> &old){        
        if(old.find(node)!=old.end()) return old[node]; 
        // graph has been copied successfully
        // if(!node) return NULL;
        Node* copy=new Node(node->val);
        old[node]=copy;
        for(auto n:node->neighbors){
            copy->neighbors.push_back(clone(n,old));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> old;
        return (node!=NULL)?clone(node,old):NULL;
    }
};