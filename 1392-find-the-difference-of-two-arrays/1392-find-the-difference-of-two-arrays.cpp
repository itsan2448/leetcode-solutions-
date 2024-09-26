class Solution {
public:
    vector<int> diff(vector<int>& n1, vector<int>& n2){
        unordered_set<int> s1(n1.begin(),n1.end());
        unordered_set<int> s2(n2.begin(),n2.end());
        vector<int> tmp;
        for(auto i:s1){
            if(s2.find(i)==s2.end()) tmp.push_back(i);            
        }
        
        return tmp;
    }
    vector<vector<int>> findDifference(vector<int>& n1, vector<int>& n2) {
        return {diff(n1,n2),diff(n2,n1)};
    }
};