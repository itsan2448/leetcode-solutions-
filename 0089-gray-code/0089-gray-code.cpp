class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        for(int i=0;i<pow(2,n);i++){
            int g=i^(i>>1);
            gray.push_back(g);
        }
        return gray;
    }
};