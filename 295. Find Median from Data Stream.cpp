class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

public:
    MedianFinder() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() >= num)
            maxHeap.push(num);
        else
            minHeap.push(num);
        if(maxHeap.size() == minHeap.size() + 2){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        else if(maxHeap.size() + 2 == minHeap.size()){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
    }

    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return ((double)(maxHeap.top() + minHeap.top()) / 2);
        else if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else
            return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
