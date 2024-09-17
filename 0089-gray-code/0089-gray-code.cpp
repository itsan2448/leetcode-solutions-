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

// gray code for 4:

// 0 1 0 0 (i)
//   0 1 0 (i>>1)
// 0 1 1 0 (ans)