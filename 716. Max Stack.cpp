#include<bits/stdc++.h>
using namespace std;

class MaxStack {
private:
    list<int> nums;
    map<int, stack<list<int>::iterator>, greater<int>> om;

public:
    MaxStack() {

    }

    void push(int x) {
        nums.push_front(x);
        om[x].push(nums.begin());
    }

    int pop() {
        int x = nums.front();
        nums.pop_front();
        auto it = om.find(x);
        it->second.pop();
        if(it->second.empty())
            om.erase(it);
        return x;
    }

    int top() {
        return nums.front();
    }

    int peekMax() {
        return om.begin()->first;
    }

    int popMax() {
        auto it = om.begin();
        int x = it->first;
        nums.erase(it->second.top());
        it->second.pop();
        if(it->second.empty())
            om.erase(it);
        return x;
    }
};
