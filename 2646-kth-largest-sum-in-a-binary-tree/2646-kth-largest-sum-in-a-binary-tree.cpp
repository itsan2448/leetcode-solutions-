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
    priority_queue<long long,vector<long long>,greater<>> pq;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long s=0;
            int z=q.size();
            for(int i=0;i<z;i++){
                TreeNode* n=q.front();
                q.pop();
                s+=n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            pq.push(s);
            if(pq.size()>k)pq.pop();
        } 
        
        return (pq.size()<k)?-1:pq.top();
    }
};