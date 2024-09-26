class MyCalendarTwo {
public:
    map<int,int> m;    

    MyCalendarTwo() {}
    bool book(int start, int end) {    
        m[start]++; // activation
        m[end]--; // deactivation
        int bookings=0;
        for(auto i:m){
            bookings+=i.second;
            if(bookings==3){
                m[start]--;
                m[end]++;
                return 0;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */