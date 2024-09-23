class Solution {
public:
    int longestValidParentheses(string str) {
        int n=str.size(), o=0,c=0,ans=0;
        
        for(int i=0;i<n;i++){
            if(str[i]=='(') o++;
            else c++;
            
            if(o==c)
                ans=max(ans,o*2); // making a valid pair
            else if(c>o) //if any time no of ) > ( make their count 0
                o=c=0;
        }        
        o=c=0;
        for(int i=n-1;i>=0;i--){
            if(str[i]=='(') o++;
            else c++;

            if(o==c)
                ans=max(ans,o*2); // making a valid pair
            else if(c<o)
                o=c=0;
        }
        return ans;
    }
};