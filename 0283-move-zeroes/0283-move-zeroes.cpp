class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i=0,j=1;

        while(j<a.size()){
            if(a[i]!=0){
                i++;
            }else if(a[j]!=0){
                swap(a[i],a[j]);
                i++;
            }

            j++;
        }

    }
};