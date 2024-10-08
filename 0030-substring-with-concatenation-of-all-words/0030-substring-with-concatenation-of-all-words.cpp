class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        int l=w[0].length();
        int x=w.size();
        int winsize=l*x;
        vector<int> ans;
        unordered_map<string,int> f;
        for(auto i:w){
            f[i]++;
        }
        for(int i=0;i<l;i++){
            unordered_map<string,int> seen;            
            int j=i;    // left ptr
            int c=0;    // count of matched words     
            for(int k=i;k+l<=s.size();k+=l){ //k is right ptr
                string a=s.substr(k,l);                
                if(f.find(a)!=f.end()){
                    seen[a]++;
                    c++;
                    while(seen[a]>f[a]){
                        string lw=s.substr(j,l);
                        seen[lw]--;
                        c--;
                        j+=l;
                    }
                    if(c==x) ans.push_back(j);
                }else{
                    seen.clear();
                    c=0;
                    j=k+l;
                }
            }
        }
        return ans;
    }
};