class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> l(n,0);
        int a=1;
        for(int i=0;i<n;i++){
            l[i]=a;
            if(a*10>n){
                if(a==n) a/=10; // for n=13,, here a=14,, so a/=10 = 1;
                a++;
                while(a%10 == 0) a/=10; //remove trailing 0s 
                // consider for case, n=5000
            }else{
                a*=10;
            }
        }
        return l;
    }
};