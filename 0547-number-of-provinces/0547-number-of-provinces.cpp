class Solution {
public:
    void dfs(unordered_map<int,bool> &vis, unordered_map<int,vector<int>> &adj, int start){
        if(vis[start]==0){
            vis[start]=1;
            for(auto j:adj[start]){
                if(vis[j]==0) dfs(vis,adj,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        int ans=0;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j])
                adj[i].push_back(j);
            }
        }
        unordered_map<int,bool> vis;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vis,adj,i);
                ans++;
            }
        }
        return ans;
    }
};