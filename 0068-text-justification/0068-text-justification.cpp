class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int m) {
        
        vector<string> f; // result
        vector<string> line; // line of all words that we can accomodate in a line
        int len=0; // length of current line
        
        for(auto i:w){
            if(i.size() + len + line.size() > m){
                // line complete
                int x_sp = m - len;
                int sp = x_sp / max(static_cast<size_t>(1),line.size()-1); // div by no. of (word-1)
                int rem_sp = x_sp % max(static_cast<size_t>(1),line.size()-1); 

                for(int j=0;j<max(static_cast<size_t>(1),line.size()-1);j++){                    
                    line[j]+=string(sp,' '); //add sp spaces                    
                    if(rem_sp){ // distr rem spaces
                        line[j]+=" ";
                        rem_sp--;
                    }
                }
                string tmp="";
                for(auto j:line){
                    tmp+=j;
                }
                f.push_back(tmp);
                line.clear();
                len=0;
            }
            line.push_back(i);
            len += i.size();
        }

        // end line
        string last="";
        for(int i = 0; i < line.size(); ++i) {
            last += line[i];
            if (i != line.size() - 1) last += " ";            
        }
             
        last += string(m-last.size(),' ');
        
        f.push_back(last);

        return f;
    }
};