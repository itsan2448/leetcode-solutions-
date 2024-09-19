class Solution {
public:
    vector<int> diffWaysToCompute(string x) {
        vector<int> v;
        
        for(int i=0;i<x.size();i++){
            if(x[i]=='+' || x[i]=='-' || x[i]=='*'){
                vector<int> x1=diffWaysToCompute(x.substr(0,i));
                vector<int> x2=diffWaysToCompute(x.substr(i+1));                
                for(auto j:x1){
                    for(auto k:x2){
                        if(x[i]=='+'){
                            v.push_back(j+k);
                        }else if(x[i]=='-'){
                            v.push_back(j-k);
                        }else{
                            v.push_back(j*k);
                        }
                    }
                }
            }
        }
        if(v.empty()) return {stoi(x)};
        return v;
    }
};