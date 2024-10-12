class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq; // max heap
        for(int i=0;i<n1.size();i++){
            for(int j=0;j<n2.size();j++){
                int s=n1[i]+n2[j];
                if(pq.size()<k){
                    pq.push({s,{n1[i],n2[j]}});
                }else if(pq.top().first>s){
                    pq.pop(); //remove pairs with large sums
                    pq.push({s,{n1[i],n2[j]}});
                }else {
                    break;
                }
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};