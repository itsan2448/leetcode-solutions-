class MyCalendarThree {
public:
    map<int,int> m;    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int ans=0;
        m[start]++; // activation
        m[end]--; // deactivation
        int bookings=0;
        for(auto i:m){
            bookings+=i.second;
            ans=max(ans,bookings);
            // if(bookings==3){
            //     m[start]--;
            //     m[end]++;
            //     return 0;
            // }
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */