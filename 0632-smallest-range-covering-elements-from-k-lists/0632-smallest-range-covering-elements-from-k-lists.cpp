class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        int left=INT_MAX;
        int right=INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0;i<k;i++){           
            pq.push({nums[i][0],i,0}); // n,index,index of n 
            left=min(left,nums[i][0]);
            right=max(right,nums[i][0]);    
        }
        vector<int> res={left,right};
        while(true){
            vector<int> c=pq.top();
            pq.pop();
            int n=c[0],i=c[1],idx=c[2]; 
            // n=number
            // i = index of vector
            // idx = index in vector
            if(right-left<res[1]-res[0]){
                res={left,right};
            }              
            if(idx+1<nums[i].size()){
                int next_val=nums[i][idx+1];
                pq.push({next_val,i,idx+1});
                right=max(right,next_val);
                left=pq.top()[0];
            }else{
                break;
            }
        }
        return res;
    }
};