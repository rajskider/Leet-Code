class MinStack {
public:
    stack<int> minSt;
    stack<int> st;
    MinStack() {}
    
    void push(int value) {
        st.push(value);
        if(!minSt.empty()){
            int num = min(value, minSt.top());
            minSt.push(num);
        }
        else minSt.push(value);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */