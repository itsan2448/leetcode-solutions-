class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int> ms;
        for(auto i:tp){
            int s=0;
            int a=stoi(i.substr(0,2));
            
            s+=(a*60)+stoi(i.substr(3,2));
            ms.push_back(s);
        }
        
        sort(ms.begin(),ms.end());

        int ans=INT_MAX;
        for(int i=1;i<ms.size();i++){
            ans=min(ans,ms[i]-ms[i-1]);
        }

        return min(ans, abs(1440+ms[0]-ms[ms.size()-1]));

    }
    

};