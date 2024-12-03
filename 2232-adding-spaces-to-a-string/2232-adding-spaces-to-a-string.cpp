class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0,j=0;
        string ans="";
        
        for(i;i<s.size();i++){
            if(j<spaces.size() && i==spaces[j]){
                ans+=' ';
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};