class Solution {
public:
    int minSubarray(vector<int>& s, int p) {
        int n=s.size();
        int ans=n;
        long sum=0;
        for(auto i:s){
            sum+=i;
        }
        int rem=sum%p;
        if(rem==0) return 0;        
        
        long presum=0;
        unordered_map<int,int> pre; // store position for each (sum%p)
        pre[0]=-1;
        for(int i=0;i<n;i++){
            presum+=s[i];
            int cur_mod= presum%p;
            int tar_mod= (-rem+cur_mod+p)%p;
            if(pre.find(tar_mod)!=pre.end()){
                ans=min(ans,i-pre[tar_mod]);
            }
            pre[cur_mod]=i;
        }
        if(ans==n) return -1;
        return ans;
    }
};