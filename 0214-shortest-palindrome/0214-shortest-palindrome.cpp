class Solution {
public:
    
    string shortestPalindrome(string s) {
        if(s.size()<2) return s;
        int n=s.size();
        int i=0,j=n-1;

        // finding lpp - longest prefix palindrome
        while(j>=0){
            if(s[i]==s[j]){
                i++;
            }
            j--;
        }
        string rem=s.substr(i);
        if(rem.empty()) return s;

        string rev_rem=rem;
        reverse(rev_rem.begin(),rev_rem.end());
        cout<< rev_rem <<" "<< s.substr(0,i) <<" "<< rem<<endl;

        return rev_rem+ shortestPalindrome(s.substr(0,i)) +rem;
    }
};