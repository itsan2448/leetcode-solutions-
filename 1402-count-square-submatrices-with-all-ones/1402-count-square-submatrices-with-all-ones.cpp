class Solution {
public:
    int countSquares(vector<vector<int>>& x) {
        int n=x.size(),m=x[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1][j-1]==1){
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};