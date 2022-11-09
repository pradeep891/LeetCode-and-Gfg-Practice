class StockSpanner {
public:
    stack< pair<int , int> >stock;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ct = 1;
        while(stock.empty() == false && stock.top().first <= price){
            ct+= stock.top().second;
            stock.pop();
        }
        
        stock.push({price , ct});
        return ct;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */