class MyCircularDeque {
public:
    vector<int> dq;
    int f,b,s,c; //front, back, size, capacity
    MyCircularDeque(int k) {
        dq=vector<int>(k,-1);
        f=0;b=0;s=0;c=k;
    }
    bool insertFront(int value) {
        if(isFull()) return 0;
        if(f==0)f=c-1;        
        else f--;
        dq[f]=value;
        s++;
        return 1;
    }
    bool insertLast(int value) {
        if(isFull()) return 0;
        dq[b]=value;
        if(b==c-1)b=0;
        else b++;
        s++;
        return 1;
    }
    bool deleteFront() {
        if(isEmpty()) return 0;
        dq[f]=-1;
        if(f==c-1) f=0; // wrap
        else f++;
        s--;
        return 1;
    }
    bool deleteLast() {
        if(isEmpty()) return 0;
        if(b==0) b=c-1; // wrap
        else b--;
        s--;
        dq[b]=-1;
        return 1;
    }
    int getFront() {
        if (isEmpty())return -1;
        return dq[f];
    }
    int getRear() {
        if (isEmpty())return -1; 
        if (b==0)
        return dq[c-1]; // Wrap around to the last valid element 
        else 
        return dq[b-1]; // Get the last element
    }
    bool isEmpty() {
        return s==0;
    }
    bool isFull() {
        return s==c;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */