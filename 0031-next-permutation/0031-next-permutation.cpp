class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        int i=n-2,j=n-1;
        while(i>=0 && a[i]>=a[i+1]){
            i--;
        }
        if(i>=0){                    
            while(a[j]<=a[i]){
                j--;        
            }
            swap(a[i],a[j]);
        }
        reverse(a.begin()+i+1,a.end());        
    }
};