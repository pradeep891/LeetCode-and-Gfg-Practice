class MedianFinder {
public:
    // vector<int>store;
    priority_queue<int , vector<int> , greater<int> >right;
    priority_queue<int>left;
    int sz = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(sz % 2 == 0){
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        else{
            left.push(num);
            right.push(left.top());
            left.pop();
        }   
        sz++;
        
        
//         printl(left);
//         printr(right);
    }
    
    double findMedian() {
        if(sz % 2 )
            return left.top();
        
        double sum = left.top() + right.top();
        sum /= 2;
        return sum;
    }
    void printl(priority_queue<int>left){
        cout << "Left = ";
        while(left.empty() == false)
        {
            cout << left.top() << " ";
            left.pop();
        }
        cout << endl;
    }
    void printr(priority_queue<int , vector<int> , greater<int> >left){
        cout << "Right = ";
        while(left.empty() == false)
        {
            cout << left.top() << " ";
            left.pop();
        }
        cout << endl;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */