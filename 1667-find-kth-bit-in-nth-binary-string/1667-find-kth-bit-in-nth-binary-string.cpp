class Solution {
public:
    string inv_rev(string s){
        if(s=="") return s;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        
        for(int i=1;i<n;i++){
            string tmp=s+'1'+inv_rev(s);
            s=tmp;
        }
        return s[k-1];
    }
};