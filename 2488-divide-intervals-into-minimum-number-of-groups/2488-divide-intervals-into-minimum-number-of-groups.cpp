class Solution {
public:
    int minGroups(vector<vector<int>>& i) {
        
        vector<int> s,e; //start,end
        for(auto j:i){
            s.push_back(j[0]);
            e.push_back(j[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());

        int ptr=0,ans=0;

        for(auto j:s){
            if(j>e[ptr]) ptr++;
            else ans++;
        }
        return ans;
    }
};