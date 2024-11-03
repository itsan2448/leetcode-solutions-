class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minCapital;  
        priority_queue<int,vector<int>> maxProfit; // projects we can afford rn
        int n=profits.size();
        for(int i=0;i<n;i++){
            minCapital.push({capital[i],profits[i]});            
        }
        while(k--){
            while(!minCapital.empty() && minCapital.top().first<=w){
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }
            if(maxProfit.empty()) break;
            w+=maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};