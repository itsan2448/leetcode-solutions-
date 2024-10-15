class Solution {
public:
    pair<int,int> row_col_coor(int n,vector<vector<int>>& b, int i){
        int r=(i-1)/n,c=(i-1)%n;
        if(r%2==1) c=n-1-c;
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& b) {
        reverse(b.begin(),b.end()); //reversing to make calculations a bit easier
        int n=b.size();
        queue<pair<int,int>> q; // [sqaure,moves]
        q.push({1,0}); // we start from 1, moves=0 then
        set<int> vis; // finding if it's unvisited
        while(!q.empty()){
            pair<int,int> c=q.front(); //square, moves
            q.pop();
            int sq=c.first; // the current sqare
            int mov=c.second; // moves taken to reach it
            for(int i=1;i<=6;i++){ // 1-6 possible dice outputs
                int nxtsq= sq + i; // the next sq is cur sq + dice output
                pair<int,int> p = row_col_coor(n,b,nxtsq);
                int r=p.first,c=p.second;
                // cout<<c<<","<<r<<endl;
                if(b[r][c]!=-1){ // if we find a ladder or snake
                    nxtsq=b[r][c]; // next sq is where that ends
                }
                if(nxtsq==n*n){ //if we have reached the final position
                    return mov+1;
                }
                if(vis.find(nxtsq)==vis.end()){ //if next sq is a new position 
                    vis.insert(nxtsq);
                    q.push({nxtsq,mov+1}); // add it in queue
                }
            }
        }
        return -1;
    }
};