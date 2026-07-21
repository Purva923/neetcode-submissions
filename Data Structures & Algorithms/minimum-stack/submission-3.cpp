class MinStack {
    private:
    stack <int> nums;
    stack <int> mins;
public:
    MinStack() {}
    
    void push(int val) {
        if(nums.empty()||val<=mins.top())
        {
            mins.push(val);
            nums.push(val);
        }
        else
        {
            nums.push(val);
        }
    }
    
    void pop() {
        if(nums.empty())
        return;
        if(nums.top()==mins.top())
        mins.pop();
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
