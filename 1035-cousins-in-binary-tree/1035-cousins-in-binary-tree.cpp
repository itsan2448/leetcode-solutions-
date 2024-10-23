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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return 0;
        unordered_map<int,pair<int,int>> m; //node val, (parent val, level)
        int level=1;
        queue<pair<TreeNode*,TreeNode*>> q; // node,parent

        if(root->left){
            q.push({root->left,root});
            m[root->left->val]={root->val,level};
        }
        
        if(root->right){
            q.push({root->right,root});
            m[root->right->val]={root->val,level};
        }              

        while(!q.empty()){
            level++;
            int x=q.size();
            for(int i=0;i<x;i++){
                auto s=q.front();
                TreeNode* node=s.first;
                q.pop();
                if(node->left){
                    q.push({node->left,node});
                    m[node->left->val]={node->val,level};
                }
                if(node->right){
                    q.push({node->right,node});
                    m[node->right->val]={node->val,level};
                } 
            }
        }

        return (m[x].first!=m[y].first && m[x].second==m[y].second)? 1:0; //parent val dif, level same
    }
};