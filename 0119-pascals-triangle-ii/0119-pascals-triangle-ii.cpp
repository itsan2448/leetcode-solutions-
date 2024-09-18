class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> dp={1};        
        
        for(int i=1;i<=n;i++){
            for(int i=dp.size()-1;i>=1;i--){
                dp[i]+=dp[i-1];
            }
            dp.push_back(1);
            
        }
        return dp;
    }
};