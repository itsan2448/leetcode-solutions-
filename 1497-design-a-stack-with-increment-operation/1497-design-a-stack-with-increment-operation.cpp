class CustomStack {
public:
    vector<int> st;
    int top;
    int capacity;

    CustomStack(int n) {
        st=vector<int>(n,-1);
        top=-1;
        capacity=n;
    }
    
    void push(int x) {
        if(top==capacity-1){
            return;
        }
        st[++top]=x;
    }
    
    int pop() {
        if(top==-1){
            return -1;
        }
        return st[top--];        
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */