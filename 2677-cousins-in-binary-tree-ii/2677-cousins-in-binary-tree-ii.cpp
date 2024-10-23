/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return NULL;
        vector<int> lev;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            int s=0;
            for(int i=0;i<x;i++){
                TreeNode* t=q.front();
                q.pop();
                s+=t->val;   
                if(t->left) q.push(t->left);             
                if(t->right) q.push(t->right);         
            }
            lev.push_back(s);
        }
        int level=1;
        q.push(root);
        root->val=0;
        while(!q.empty()){
            int x=q.size();
            
            for(int i=0;i<x;i++){
                TreeNode* n=q.front();
                q.pop();
                int sum=0;
                if(n->left){ 
                    sum+=n->left->val;
                    q.push(n->left);
                }
                if(n->right){ 
                    sum+=n->right->val;
                    q.push(n->right);
                }

                if(n->left) n->left->val=lev[level]-sum;
                if(n->right) n->right->val=lev[level]-sum;
                
            }
            level++;
        }
        return root;
    }
};