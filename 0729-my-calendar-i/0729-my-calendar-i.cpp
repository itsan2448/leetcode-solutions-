class MyCalendar {
public:
    vector<pair<int,int>> v;

    MyCalendar() {}
    
    bool book(int start, int end) {
        for(auto p:v){
            if(p.first<end && p.second>start) return 0;
        }
        v.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */