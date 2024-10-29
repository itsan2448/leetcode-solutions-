class Solution {
public:
    
    int maxMoves(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[i][m-1]=1; // last colm =1
        }
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){            
                int x=g[i][j];
                // e
                int mxmove=0;
                if(x<g[i][j+1])
                mxmove=dp[i][j+1];
                // n-e
                if(i>0 && x<g[i-1][j+1])
                mxmove=max(mxmove,dp[i-1][j+1]);
                // s-e
                if(i<n-1 && x<g[i+1][j+1])
                mxmove=max(mxmove,dp[i+1][j+1]);
                dp[i][j]=1+mxmove;
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans-1;
    }
};