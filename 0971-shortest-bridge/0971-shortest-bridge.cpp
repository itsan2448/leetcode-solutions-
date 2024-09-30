class Solution {
public:
    bool invalid(int r,int c,int n){
        return (r<0 || c<0 || r>=n || c>=n); 
    }

    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; // directions
    set<pair<int,int>> vis;

    void dfs(int r,int c,int n,vector<vector<int>>& grid){ 
        // find any 1 of the island first
        if(invalid(r,c,n) || grid[r][c]==0 || vis.find({r,c})!=vis.end()){
            return;
        }
        vis.insert({r,c});
        for(auto i:dir){
            dfs(r+i.first,c+i.second,n,grid);
        }
    }

    int bfs(int n,vector<vector<int>>& grid){
        // shortest distance of 2nd island from 1st island
        int res=0;
        queue<pair<int,int>> q;
        for(auto i:vis){
            q.push({i.first,i.second});
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();
                q.pop();
                for(auto i:dir){
                    int cr=p.first+i.first;
                    int cc=p.second+i.second;
                    if(invalid(cr,cc,n) || vis.find({cr,cc})!=vis.end())
                        continue;
                    if(grid[cr][cc]) return res;
                    q.push({cr,cc});
                    vis.insert({cr,cc});
                }
            }
            res++;
        }
        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid){
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,n,grid);   
                    return bfs(n,grid);
                }
            }
        }
        return -1;
    }
};