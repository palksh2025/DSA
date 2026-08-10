class MinStack {
public:
    stack<int> st;

    stack<int> stMin;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);

        if(stMin.empty()){
            stMin.push(value);
            return;
        }

        if(value <= stMin.top()){
            stMin.push(value);
        }
    }
    
    void pop() {
        if (st.top() == stMin.top()){
            st.pop();
            stMin.pop();
        }
        else{
           st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return stMin.top(); 
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