class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size(), s = 0;
        if(n == 0)
            return 0;

        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), [&](vector<int> &a, vector<int> &b){
            return a.back() < b.back();
        });
        for(int i = 0; i < n; i++){
            pq.push(courses[i].front());
            s += courses[i].front();
            while(s > courses[i].back()){
                s -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
