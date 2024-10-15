class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0)); // [index, can buy]
        int buy=1; //can buy
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){ 
            for(int buy=0;buy<=1;buy++){           
                if(buy==1){ //max of buy+ can't buy, 0,can buy
                    dp[i][1]=max(dp[i+1][0]-prices[i],0+dp[i+1][1]);
                }else{
                    dp[i][0]=max(dp[i+1][1]+prices[i],0+dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};