class Solution {
public:
    vector<int> retLPS(const string& p){
        // O(n)
        int n=p.length();
        vector<int> lps(n,0);
        int prevLps=0, i=1;
        while(i<n){
            if(p[i]==p[prevLps]){
                lps[i]=prevLps+1;
                prevLps++;
                i++;
            }else if(prevLps==0){
                lps[i]=0;
                i++;
            }else{
                prevLps=lps[prevLps-1];
            }  
        }                                  
        return lps;
    }
    bool patInText(const string& txt, const string& p){
        if(p.empty()) return 1;
        if(txt.length()<p.length()) return 0;
        vector<int> lps=retLPS(p);
        int i=0,j=0;
        while(i<txt.length()){
            if(txt[i]==p[j]){
                i++;j++;
                if(j==p.length()){
                    return 1;
                }
            }else{
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return 0;
    }
    vector<string> stringMatching(vector<string>& words) {
        // O(n+m)
        vector<string> ans;
        int n=words.size();
        sort(words.begin(),words.end(),[](const string& a,const string& b)->bool{
            return a.length()<b.length();
        });
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(patInText(words[j],words[i])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};