class Solution {
public:
    double bfs(string src,string target,unordered_map<string,vector<pair<string,double>>> &adj) {
        if(adj.find(src)==adj.end()||adj.find(target)==adj.end()) return -1.0;
        queue<pair<string,double>> q;
        set<string> vis;
        q.push({src,1}); //src,wt
        vis.insert(src);
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            string n=p.first;
            double w=p.second;
            if(n==target) return w;
            for(auto nei:adj[n]){
                string nbr=nei.first;
                double wt=nei.second;
                if(vis.find(nbr)==vis.end()){
                    q.push({nbr,wt*w});
                    vis.insert(nbr);
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string,double>>> adj; // a -> [b,a/b]

        for(int i=0;i<e.size();i++){
            vector<string> s=e[i];
            string a=s[0],b=s[1];
            adj[a].push_back({b,v[i]});
            adj[b].push_back({a,1.0/v[i]});
        }
        vector<double> res(q.size());
        for(int i=0;i<q.size();i++){
            res[i]=bfs(q[i][0],q[i][1],adj);
        }
        return res;
    }
};