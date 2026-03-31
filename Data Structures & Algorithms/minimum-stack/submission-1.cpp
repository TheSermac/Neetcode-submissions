class MinStack {
private:
    stack<int> _stack;
    stack<int> _min;
public:
    MinStack() {}   
    
    void push(int val) {
        if(_min.empty() || val <= _min.top()){
            _min.push(val);
        }
        _stack.push(val);
    }
    
    void pop() {
        if(_stack.top() == _min.top()){
            _min.pop();
        }
        _stack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return _min.top();
    }
};
