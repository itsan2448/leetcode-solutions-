class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size(); //i
        if(n<=1) return 0;
        int selling = 0,  buying = -p[0], cooldown = 0;
        // no-stock - after sold or after cooldown state;
        for(int i=0;i<n;i++){
            int prv = selling ;
            selling = buying + p[i];
            buying = max( buying, cooldown - p[i]);
            cooldown = max(cooldown,prv);
        }
        return max(selling ,cooldown);
    }
};