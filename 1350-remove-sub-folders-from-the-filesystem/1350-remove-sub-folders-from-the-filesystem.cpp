class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> fol(folder.begin(),folder.end());
        vector<string> res;
        for(auto f : folder){
            res.push_back(f);
            for(int i=0;i<f.size();i++){
                if(f[i]=='/' && fol.find(f.substr(0,i))!=fol.end()){
                    res.pop_back();
                    break;
                }
            }
        }
        return res;
    }
};