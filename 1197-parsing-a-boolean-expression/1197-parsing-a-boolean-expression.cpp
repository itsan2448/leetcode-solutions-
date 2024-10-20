class Solution {
public:
    bool parseBoolExpr(string x) {
        if(x=="t") return 1;
        if(x=="f") return 0;
        stack<char> st;
        for(auto i:x){
            if(i==',' || i=='(') continue;
            if(i=='|' || i=='&' || i=='!' || i=='f' || i=='t') st.push(i);
            else if(i==')'){
                bool hasTrue=0;
                bool hasFalse=0;
                while(st.top()!='!' && st.top()!='&' && st.top()!='|'){
                    char t=st.top();
                    st.pop();
                    if(t=='t') hasTrue=1;
                    else if(t=='f') hasFalse=1;
                }
                char op=st.top();
                st.pop();
                if(op=='!'){
                st.push(hasTrue? 'f':'t');
                }else if(op=='&')
                st.push(hasFalse? 'f':'t');
                else
                st.push(hasTrue? 't':'f');
            }
        }
        return st.top()=='t';
    }
};