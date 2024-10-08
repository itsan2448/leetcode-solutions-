class Solution {
public:
    int minSwaps(string s) {
        // With one swap, you can create 
        // "two" additional pair of correctly matched 
        // brackets(since you will swap an open and a close 
        // and if you do it greadily you will be able 
        // to create 2 pairings), reducing the count 
        // of unmatched opening brackets from 3 to 1.
        
        int im=0; // count imbalances
        for(auto i:s){
            if(i==']'){ // closing bracket
                if (im==0) im++; // no opening bracket
                else im--; // opening bracket available
            }
            else im++; // only opening bracket available
        }
        return (im+1)/2; // 1 swap fizes 2 unmatched brackets
    }
};