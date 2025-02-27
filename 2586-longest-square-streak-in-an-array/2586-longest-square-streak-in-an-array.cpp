class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        if(nums.empty())return -1;
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(auto i:s){          
            int tmp=1;  //tmp streak
            int x=i; //current
            while(s.find(x)!=s.end()){
                int root=sqrt(x);
                if(root*root==x && s.find(root)!=s.end()){//perfect square
                    tmp++;                    
                    x=root;
                }else{
                    break;
                }                                          
            }   
            ans=max(ans,tmp);                    
        }
        return ans>1?ans:-1;
    }
};