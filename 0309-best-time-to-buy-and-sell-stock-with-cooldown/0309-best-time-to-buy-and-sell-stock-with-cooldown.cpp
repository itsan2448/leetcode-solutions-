class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); //i
        if(n<=1) return 0;
        // s0 - we can buy
        // s1 - we can sell
        // s2 - we take a rest
        vector<int> s0(n,0);
        vector<int> s1(n,0);
        vector<int> s2(n,0);
        
        // basecases
        s0[0]=0; // at start, no stock
        s1[0]=-prices[0]; // after buying
        s2[0]=INT_MIN; // lower base case

        for(int i=1;i<n;i++){
            s0[i]=max(s0[i-1],s2[i-1]);
            s1[i]=max(s1[i-1],s0[i-1]-prices[i]);
            s2[i]=s1[i-1]+prices[i];
        }
        return max(s0[n-1],s2[n-1]);
    }
};