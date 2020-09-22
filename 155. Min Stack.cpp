class MinStack {
private:
    stack<int> s1, s2;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            s2.push(x);
        }
        else{
            s1.push(x);
            s2.push(min(x, s2.top()));
        }
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};
