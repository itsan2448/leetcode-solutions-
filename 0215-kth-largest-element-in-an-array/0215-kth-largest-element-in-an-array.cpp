class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // minheap
        priority_queue<int,vector<int>,greater<int>> mh(nums.begin(),nums.begin()+k);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>mh.top()){
                mh.pop();
                mh.push(nums[i]);
            }
        }
        return mh.top();
    }
};