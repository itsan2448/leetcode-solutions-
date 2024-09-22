class Solution {
    int nextstep(long start,long end,long &n){ // how many numbers lie between start and end
        int range=0;
        while(start<=n){ // considering numbers up to n
            range+=min(n+1,end)-start; //if start is 1, end will be 2; if start is 10, end will be 11
            start*=10;
            end*=10;
        }
        return range;
    }
public:
    int findKthNumber(long n, int k) {        
        long a=1;//starting no.
        k--;
        while(k>0){            
            int range=nextstep(a,a+1,n);
            if(range<=k){
                k-=range;
                a++;
            }else{
                k--;
                a*=10;
            }     
        }
        return a;        
    }
};