class Solution {
public:
    int minExtraChar(string s, vector<string>& dic) {
        int n=s.length();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1; // for extra one char 0,1,...,n-1  (put max values)
            for(auto w:dic){
                int m=w.length();
                if(i>=m && s.substr(i-m,m)==w){
                    dp[i]=min(dp[i],dp[i-m]);
                }
            }
        }

        return dp[n];
    }
};