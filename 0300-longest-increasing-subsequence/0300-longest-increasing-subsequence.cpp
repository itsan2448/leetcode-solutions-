class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        set<int> s(a.begin(),a.end());        
        vector<int> b(s.begin(),s.end());        
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};