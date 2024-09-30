class Solution {
public:
    int hIndex(vector<int>& c) {
        int hi=c.size(); // no. of papers
        sort(c.begin(),c.end());
        for(int i=0;i<hi;i++){
            if(c[i]>=hi-i) return hi-i;
        }
        return 0;
    }
};