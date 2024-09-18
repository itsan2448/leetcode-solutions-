class Solution {
public:
    int numSquares(int n) {
        vector<int> q; // approaching it like coin change problem
        
        for(int i=1;i*i<=n;i++){
            q.push_back(i*i); 
        }

        int r=q.size();
        vector<vector<long long>> dp(r+1,vector<long long>(n+1,n+1)); 
        // at first making it unreachable

        for(int i=0;i<=r;i++){
            dp[i][0]=0;
        } // return 0 if sum 0 (though sum is never 0)
       
        for(int i=1;i<=r;i++){
            for(int j=1;j<=n;j++){                
                if(j>=q[i-1]){ // if valid
                    dp[i][j]=min(1+dp[i][j-q[i-1]],dp[i-1][j]);
                }else{ // invalid
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[r][n];
    }
};