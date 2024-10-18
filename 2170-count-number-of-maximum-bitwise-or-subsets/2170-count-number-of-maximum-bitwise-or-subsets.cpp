class Solution {
public:
    void backtrack(int ind,int cor,vector<int> &nums,int &count,int mx){
        if(cor==mx) count++;
        for(int i=ind;i<nums.size();i++){
            backtrack(i+1,cor|nums[i],nums,count,mx);
        }        
    }
    int countMaxOrSubsets(vector<int> &nums) {
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mx|=nums[i];
        }
        int c=0;
        backtrack(0,0,nums,c,mx);
        return c;
    }
};