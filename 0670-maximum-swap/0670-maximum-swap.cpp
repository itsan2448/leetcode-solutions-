class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        if(n<=1) return num;        
        
        int ans=num;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                if(s[i]<s[j]){
                    swap(s[i],s[j]);
                    ans=max(ans,stoi(s));
                    swap(s[i],s[j]);
                }
            }
        }
        return ans;
    }
};