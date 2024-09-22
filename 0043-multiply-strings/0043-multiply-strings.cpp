class Solution {
public:
    string multiply(string x, string y) {
        if(x=="0" || y=="0"){
            return "0";
        }

        vector<int> res(x.size()+y.size(),0); // digit(a*b) can be max digit(a)+digit(b)
        
        for(int i=x.size()-1;i>=0;i--){
            for(int j=y.size()-1;j>=0;j--){
                res[i+j+1] += (x[i]-'0')*(y[j]-'0'); //product of 2 1 digit no. at max is 81
                res[i+j] += res[i+j+1] / 10;
                res[i+j+1] %= 10;
            }
        }
        string ans="";
        int i=0;
        while(res[i]==0) i++;
        while(i<res.size()){            
            ans+=to_string(res[i]);
            i++;
        }
        return ans;
    }
};