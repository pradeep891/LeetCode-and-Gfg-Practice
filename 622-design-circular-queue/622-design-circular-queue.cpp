class MyCircularQueue {
public:
    
    vector<int>q;
    int ft=0 , rr = 0;
    int sz;
    MyCircularQueue(int k) {
        q.resize(k);
        sz = k;        
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        q[rr % sz] = value;
        rr++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        ft++;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[ft % sz];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(rr - 1) % sz];
    }
    
    bool isEmpty() {        
        return ft == rr;
    }
    
    bool isFull() {
        return ft != rr && ft % sz == rr % sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */