class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int l=pow(2,n)-1; //length
        int m=l/2+1; //mid
        if(k==m) return '1'; //length==mid
        if(k<m) return findKthBit(n-1,k);
        
        return findKthBit(n-1,l-k+1)=='0'?'1':'0';
    }
};