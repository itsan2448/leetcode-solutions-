class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        unordered_set<string> s(w.begin(),w.end());
        if(s.find(e)==s.end()) return 0;

        unordered_map<string, vector<string>> nei; // pattern -> vector(words)
        w.push_back(b);
        for(string i: w){
            for(int j=0;j<i.size();j++){
                string pattern=i;
                pattern[j]='*';
                nei[pattern].push_back(i);
            }
        }
        queue<string> q;
        unordered_set<string> vis;
        q.push(b);
        vis.insert(b);
        int ans=1;
        while(!q.empty()){            
            int k=q.size();
            for(int j=0;j<k;j++){
                string word=q.front();
                q.pop();
                if(word==e) return ans;                
                for(int i=0;i<word.size();i++){
                    string pattern=word;
                    pattern[i]='*';
                    for(auto p:nei[pattern]){
                        if(vis.find(p)==vis.end()){
                            vis.insert(p);
                            q.push(p);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};