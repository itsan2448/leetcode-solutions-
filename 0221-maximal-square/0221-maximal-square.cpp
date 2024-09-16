class Solution {
public:
    int maximalSquare(vector<vector<char>>& x) {
        int n=x.size(),m=x[0].size(),ans=INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1][j-1]=='1')
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                ans=max(ans,dp[i][j]);
            }
        }
        return pow(ans,2);
    }
};