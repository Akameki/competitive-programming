#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class MinStack {
private:
    stack<int> st;
    stack<int> mins;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (mins.empty()) mins.push(val);
        else mins.push(min(mins.top(), val));
    }
    
    void pop() {
        st.pop();
        mins.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */