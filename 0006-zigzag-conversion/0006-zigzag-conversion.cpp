class Solution {
public:
    string convert(string s, int r) {
        
        if(r==1 || r>=s.length()) return s;
        string ans="";
        int i=0,d=1; // index , direction
        vector<vector<char>> row(r);
        for(auto c:s){
            row[i].push_back(c);
            if(i==0) d=1; // when in first row, change direction -> +1
            else if(i==r-1) d=-1; // when in last row, change direction ->-1
            i+=d; // change index
        }
        for(auto i:row){
            for(auto j:i){
                ans+=j;
            }
        }
        return ans;
    }
};