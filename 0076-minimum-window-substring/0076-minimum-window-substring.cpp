class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char,int> ct,cs;
        int need=0,want=0;
        for(auto i:t){
            ct[i]++;            
        }
        need=ct.size(); // total unique characters in t
        pair<int,int> res={-1,-1};
        int reslen=INT_MAX;
        int l=0,r=0;
        
        while(r<s.length()){
            cs[s[r]]++;
            if(ct.find(s[r])!=ct.end() && ct[s[r]]==cs[s[r]]){
                want++;
            }
            while(need==want){
                if(r-l+1<reslen){
                    reslen=r-l+1;
                    res={l,r};
                }
                cs[s[l]]--;
                if(ct.find(s[l])!=ct.end() && cs[s[l]]<ct[s[l]]) want--;
                l++;
            }
            r++;
        }
        if(reslen==INT_MAX) return "";
        return s.substr(res.first,reslen);               
    }
};