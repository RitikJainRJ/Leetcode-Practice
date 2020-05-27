class FreqStack {
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> s;
    int max_freq;

public:
    FreqStack() {
        max_freq = 0;
    }

    void push(int x) {
        freq[x]++;
        s[freq[x]].push(x);
        max_freq = max(max_freq, freq[x]);
    }

    int pop() {
        int res = s[max_freq].top();
        s[max_freq].pop();
        freq[res]--;
        if(s[max_freq].empty()){
            s.erase(max_freq);
            max_freq--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
