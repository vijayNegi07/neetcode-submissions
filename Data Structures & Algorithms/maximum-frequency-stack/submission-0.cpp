class FreqStack {
private: 
    priority_queue<vector<int>> stack;
    unordered_map<int, int> cnt;
    int index;
public:
    FreqStack(): index(0){
      
    }
    
    void push(int val) {
        cnt[val]++;
        stack.push({cnt[val], index++, val});
    }
    
    int pop() {
        auto top = stack.top();
        stack.pop();
        int val = top[2];
        cnt[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */