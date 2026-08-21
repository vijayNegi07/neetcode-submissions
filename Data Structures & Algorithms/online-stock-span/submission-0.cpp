class StockSpanner {
public:
    stack<int> stocks;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        stack<int> temp;
        while(!stocks.empty() && stocks.top() <= price){
            int top = stocks.top();
            stocks.pop();
            temp.push(top);
            count++;
        }
        while(!temp.empty()){
            stocks.push(temp.top());
            temp.pop();
        }
        stocks.push(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */