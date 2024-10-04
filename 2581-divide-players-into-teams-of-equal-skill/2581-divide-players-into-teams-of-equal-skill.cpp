class Solution {
public:
    long long dividePlayers(vector<int>& sk) {
        sort(sk.begin(),sk.end());
        int i=0,j=sk.size()-1;
        long long ans=sk[i]*sk[j];
        long long sum=sk[i++]+sk[j--];
        while(i<j){
            if(sk[i]+sk[j]!=sum)
            return -1;
            ans+=(sk[i]*sk[j]);
            i++;j--;
        }
        return ans;
    }
};