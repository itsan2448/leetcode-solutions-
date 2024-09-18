bool cmp(int a,int b){
        string x=to_string(a);
        string y=to_string(b);
        return (x+y > y+x); 
    }

class Solution {
public:
    
    string largestNumber(vector<int>& a) {
        sort(a.begin(),a.end(),cmp); //desc sort
        for(auto i:a){
            cout<<i;
        }
        if(a[0]==0) return "0";
        string ans="";
        for(int i:a){
            ans+=to_string(i);
        }
        return ans;
    }
};