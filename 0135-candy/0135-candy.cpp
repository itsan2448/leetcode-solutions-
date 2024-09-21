class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> can(n,1); // every kid has min 1 candy

        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]){
                can[i]=can[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(r[i]>r[i+1]){
                can[i]=max(can[i],can[i+1]+1);
            }
        }

        int s=0;
        for(auto i:can){
            s+=i;
        }

        return s;

    }
};