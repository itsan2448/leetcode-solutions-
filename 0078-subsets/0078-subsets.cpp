class Solution {
    void backtrack(int i,vector<vector<int>> &sub,vector<int> list,vector<int>& nums){
        if(i==nums.size()){
            sub.push_back(list);
            return;
        }
        list.push_back(nums[i]);
        backtrack(i+1,sub,list,nums);
        list.pop_back();
        backtrack(i+1,sub,list,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sub;
        vector<int> list;
        backtrack(0,sub,list,nums);
        return sub;        
    }
};