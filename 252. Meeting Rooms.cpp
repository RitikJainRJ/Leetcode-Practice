class Solution {
public:
    bool canAttendMeetings(vector<Interval> &inter) {
        if(inter.empty())
            return true;
        int n = inter.size();

        sort(inter.begin(), inter.end(), [&](Interval &a, Interval &b){
            return a.start < b.start;
        });
        for(int i = 1; i < n; i++){
            if(inter[i - 1].end > inter[i].start)
                return false;
        }
        return true;
    }
};
