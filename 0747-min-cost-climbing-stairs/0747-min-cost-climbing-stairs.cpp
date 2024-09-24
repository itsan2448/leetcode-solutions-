class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        int n=c.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=c[0];
        for(int i=2;i<=n;i++){
            dp[i]=c[i-1]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n],dp[n-1]);
    }
};