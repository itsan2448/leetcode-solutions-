class Solution {
public:
    long long minimumSteps(string s) {
        long long z=0,sum=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')
            sum+=z;
            else 
            z++;            
        }
        return sum;
    }
};