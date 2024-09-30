class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        
        int r=m.size();
        int c=m[0].size();
        
        for(int i=r-2;i>=0;i--){
            for(int j=0;j<c;j++){
                int l = (j>0)?m[i+1][j-1]:INT_MAX;
                int r = (j<c-1)?m[i+1][j+1]:INT_MAX;
                int d = m[i+1][j];
                m[i][j] += min(d,min(l,r));
            }
        }
        int ans=INT_MAX;
        
        for (int j = 0; j < c; ++j) {
            ans = min(ans, m[0][j]);
        }
        return ans;
    }
};