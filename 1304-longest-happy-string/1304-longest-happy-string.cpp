class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s="";
        
        priority_queue<pair<int,char>> pq;
        if (a>0) pq.push({a,'a'});
        if (b>0) pq.push({b,'b'});
        if (c>0) pq.push({c,'c'});
        while(!pq.empty()){
            auto [n,c] =pq.top();            
            pq.pop();
            if(s.size()>=2 && s[s.size()-1]==c && s[s.size()-2]==c){
                if(pq.empty()) break;
                auto [m,d]=pq.top();
                pq.pop();
                s+=d;
                m--;
                if(m>0) pq.push({m,d});
                pq.push({n,c});
            }else{
                s+=c;
                n--;
                if(n>0) pq.push({n,c});
            }
        }
        return s;
    }
};