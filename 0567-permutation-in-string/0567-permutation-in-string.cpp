class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        if(n>m) return 0;

        unordered_map<char,int> m1, m2;

        for(auto i:s1){
            m1[i]++;
        }
        
        for(int i=0;i<n;i++){
            m2[s2[i]]++;
        }
        if(m1==m2) return 1;
        
        int i=n;
        
        while(i<m){
            m2[s2[i]]++;
            m2[s2[i-n]]--;
            if (m2[s2[i-n]]==0) {
                m2.erase(s2[i-n]);
            }
            if(m1==m2) return 1;     
            i++;                   
        }
        
        return 0;
    }
};