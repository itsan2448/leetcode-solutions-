class Solution {
public:
    int calculate(string s) {
        s+='+';
        stack<int> st;
        char op = '+';
        int a=0;
        for(int i=0;s[i];i++){
            if(isdigit(s[i])){
                a=a*10+(s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i]!=' '){
                if(op=='+') st.push(a);
                else if(op=='-') st.push(-a);
                else if(op=='*'){
                    int tmp=st.top();
                    st.pop();
                    st.push(tmp*a);
                }
                else if(op=='/'){
                    int tmp=st.top();
                    st.pop();
                    st.push(tmp/a);
                }
                op=s[i];
                a=0;
            }            
        }
        a=0;
        while(!st.empty()){
            a+=st.top();st.pop();
        }
        return a;
    }
};