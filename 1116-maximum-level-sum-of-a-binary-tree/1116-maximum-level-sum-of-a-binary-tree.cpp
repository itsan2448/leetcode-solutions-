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
    int maxLevelSum(TreeNode* root) {
        // priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        queue<TreeNode*> q;
        long long mx=LLONG_MIN;
        map<long long,int> fr;
        q.push(root);
        int x=1;
        while(!q.empty()){
            long long s=0;
            int z=q.size();
            for(int i=0;i<z;i++){
                TreeNode * m=q.front();                
                q.pop();
                s+=m->val;
                if(m->left) q.push(m->left);
                if(m->right) q.push(m->right);
            }
            mx=max(mx,s);
            if(fr.find(s)==fr.end()) fr[s]=x++;
            // if(pq.empty() || s>pq.top().first) pq.push({s,x++});
            // if(pq.size()>1)pq.pop();
        }                
        // return pq.top().second;
        return fr[mx];
    }
};