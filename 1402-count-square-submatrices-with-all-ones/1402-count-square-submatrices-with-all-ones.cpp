class Solution {
public:
    int countSquares(vector<vector<int>>& x) {
        int n=x.size(),m=x[0].size();        
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=x[i][0];
        }
        for(int j=1;j<m;j++){
            ans+=x[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(x[i][j]==1){                    
                    x[i][j]=1+min(x[i-1][j],min(x[i-1][j-1],x[i][j-1]));
                    ans+=x[i][j];
                }
            }
        }
        return ans;
    }
};