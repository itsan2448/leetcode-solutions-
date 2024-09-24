class Solution {
public:
    int len(int i){
        int l=0;
        while(i){
            l++;
            i/=10;
        }
        return l;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        map<int,int> mp;
        for(auto i:arr1){
            while(i){
                mp[i]++;
                i/=10;
            }
        }
        for(auto i:arr2){
            while(i){
                if(mp.find(i)!=mp.end()){        
                    ans=max(ans,len(i));                    
                }
                i/=10;
            }
        }
        return ans;
    }
};