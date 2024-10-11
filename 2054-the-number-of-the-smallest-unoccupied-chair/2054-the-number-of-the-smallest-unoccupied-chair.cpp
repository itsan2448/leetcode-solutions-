class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        for(int i=0;i<times.size();i++){
            times[i].push_back(i);
        }
        sort(times.begin(),times.end());
        priority_queue<int, vector<int>, greater<int>> available; //minheaps
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> used; //minheaps
        // l,chair
        int n=times.size();
        for(int i=0;i<n;i++){
            available.push(i);
        }
        for(auto i:times){
            while(!used.empty() && used.top().first<=i[0]){ //leave time is <= arrival time
                pair<int,int> p=used.top();
                used.pop();
                available.push(p.second);
            } 
            int chair = available.top();
            available.pop();
            used.push({i[1],chair});

            if(i[2]==t) return chair;
        }
        return -1;
    }
};