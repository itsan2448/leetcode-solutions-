class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        for(auto i:nums){
            pq.push(i);
        }
        long long s=0;
        while(!pq.empty() && k--){
            int n=pq.top();
            pq.pop();
            s+=n;
            
            pq.push(ceil(n/3.0));
        }
        return s;
    }
};