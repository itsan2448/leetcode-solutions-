#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // 2 mean heaps
        ll ans=0,mx=0;
        priority_queue<ll,vector<ll>,greater<ll>> available;      
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> used;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++){
            available.push(i);
        }
        vector<ll> f(n,0);
        for(auto i:meetings){
            
            while(!used.empty() && used.top().first<=i[0]){ //end time <=start time
                int r=used.top().second;
                used.pop();
                available.push(r);
            }
            // room available
            if(!available.empty()){
                int room=available.top();
                available.pop();
                f[room]++;            
                used.push({i[1],room});
                continue;
            } 
            // room unavailable
            pair<long,long> p=used.top();
            ll least_end_time=p.first;
            int m_room=p.second;
            used.pop();
            f[m_room]++;            
            used.push({least_end_time + i[1] - i[0], m_room});                     
        }
        for(int i=0;i<n;i++){
            if(f[i]>mx){
                mx=f[i];
                ans=i;
            }
        }
        return ans;
    }
};