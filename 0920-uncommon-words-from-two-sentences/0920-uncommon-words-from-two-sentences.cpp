class Solution {

    void store(map<string,int> &m, string s){
        stringstream ss(s);
        string w;
        while(ss>>w){
            m[w]++;
        }
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v;
        map<string,int> m1;
        map<string,int> m2;
        store(m1,s1);
        store(m2,s2);
        for(auto i:m1){
            if(m1[i.first]==1 && m2[i.first]==0){
                v.push_back(i.first);
            }
        }
        for(auto i:m2){
            if(m2[i.first]==1 && m1[i.first]==0){
                v.push_back(i.first);
            }
        }
        return v;       
    }
};