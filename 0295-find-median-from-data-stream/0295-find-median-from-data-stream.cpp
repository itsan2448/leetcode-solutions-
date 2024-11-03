class MedianFinder {
public:
    priority_queue<int,vector<int>> small;
    priority_queue<int,vector<int>,greater<int>> large;
    
    MedianFinder() {        
    }
    
    void addNum(int num) {
        small.push(num);
        // every element in small is < than every element in large
        //  log(n)
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            int val=small.top();
            large.push(val);
            small.pop();
        }
        if (small.size()>large.size()+1){
            int val=small.top();
            large.push(val);
            small.pop();
        }
        else if (large.size()>small.size()+1){
            int val=large.top();
            small.push(val);
            large.pop();
        }
    }
    
    double findMedian() {
        if(large.size()>small.size()) return double(large.top());
        if(large.size()<small.size()) return double(small.top());
        return (large.top()+small.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */