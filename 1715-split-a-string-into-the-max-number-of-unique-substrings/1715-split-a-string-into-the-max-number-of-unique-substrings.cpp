class Solution {
public:
    int helper(unordered_set<string> &subs,string s,int b){
        if(b==s.size()) return 0;
        int ans=0;
        for(int e=b+1;e<=s.size();e++){ //producing all possible substrings
            string tmp=s.substr(b,e-b);
            if(subs.find(tmp)==subs.end()){
                subs.insert(tmp);
                ans=max(ans,1+helper(subs,s,e));
                subs.erase(tmp);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> subs; 
        return helper(subs,s,0);    //set, string, begin_index        
    }
};