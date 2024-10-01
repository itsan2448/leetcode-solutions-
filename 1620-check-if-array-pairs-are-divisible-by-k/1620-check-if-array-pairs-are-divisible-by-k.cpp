class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> f;
        for(auto i:arr){
            f[((i%k)+k)%k]++;
        }
        if(f[0]%2!=0) return false;

        for(int i=1;i<=k/2;i++){
            if(f[i]!=f[k-i]) return 0;
        }
        
        return 1;
    }
};