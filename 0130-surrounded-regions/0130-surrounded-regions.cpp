class Solution {
public:
    vector<pair<int,int>> dir= {{1,0},{0,1},{-1,0},{0,-1}};
    bool invalid(int i,int j,vector<vector<char>>& b){
        return (i < 0 || i >= b.size() || j < 0 || j >= b[0].size());
    }
    void dfs(int i,int j,vector<vector<char>>& b){
        if(invalid(i,j,b) || b[i][j]=='X' || vis.find({i,j})!=vis.end()){
            return;
        }        
        vis.insert({i,j});
        b[i][j]='S';
        for(auto k:dir){
            int r=k.first+i;
            int c=k.second+j;            
            dfs(r,c,b);        
        }
    }
    set<pair<int,int>> vis;

    void solve(vector<vector<char>>& b) {
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if((i==0 || i==b.size()-1 ||j==0 || j==b[0].size()-1) && b[i][j]=='O'){
                    dfs(i,j,b);
                }
            }
        }

        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                if(b[i][j]=='O' && vis.find({i,j})==vis.end())
                b[i][j]='X';
                else if(b[i][j]=='S') 
                b[i][j]='O';
            }
        }
    }
};