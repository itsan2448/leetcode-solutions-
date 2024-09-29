class Solution {
public:
    int mx=0,ans=0;
    void dfs(int h, unordered_map<int,vector<int>> &adj, vector<bool> &vis,vector<int>& i){
        mx=max(mx,ans);
        if(!vis[h]){
            vis[h]=1;
            for(auto j:adj[h]){
                ans+=i[h];
                dfs(j,adj,vis,i);
                ans-=i[h];
            }
        }
    }
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& i) {
        if(n==1) return 0;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<m.size();i++){
            if(m[i]!=-1)
            adj[m[i]].push_back(i);
        }
        vector<bool> vis(n,0);
        dfs(h,adj,vis,i);
        return mx;
    }
};