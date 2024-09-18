class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1) return {{1}};
        vector<int> dp={1};        
        vector<vector<int>> pas;
        pas.push_back(dp);
        for(int i=1;i<n;i++){
            for(int i=dp.size()-1;i>=1;i--){
                dp[i]+=dp[i-1];
            }
            dp.push_back(1);
            pas.push_back(dp);
        }
        return pas;
    }
};

// 1
// 1 1
// 1 2 1
// 1 3 3 1