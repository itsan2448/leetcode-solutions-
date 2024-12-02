class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // unordered_map<int,int> m;
        // for(int i=0;i<arr.size();i++){
        //     m[i]=
        // }
        unordered_set<int> s;
        for(auto i :arr){
            if(s.find(2*i)!=s.end()) return 1;
            else if(i%2==0 && s.find(i/2)!=s.end()) return 1;
            // else if(i%2==1 && s.find(i/2)!=s.end())
            // else return 0;            
            s.insert(i);
        }
        return 0;
    }
};