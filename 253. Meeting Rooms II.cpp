class Solution {
public:
    int minMeetingRooms(vector<Interval> &inter) {
        if(inter.empty())
            return 0;
        int mini = INT_MAX, maxi = INT_MIN, n = inter.size();
        int res = 0, count = 0;

        for(int i = 0; i < n; i++)
            mini = min(mini, inter[i].start), maxi = max(maxi, inter[i].end);
        int size = maxi - mini + 2;
        vector<int> dp(size, 0);
        for(int i = 0; i < n; i++){
            int s = inter[i].start;
            int e = inter[i].end;
            dp[s - mini]++;
            dp[e - mini + 1]--;
        }
        for(int i = 0; i < size; i++){
            count += dp[i];
            res = max(res, count);
        }
        return res;
    }
};

/////////////////////////////////////////////////
class Solution {
public:
    int minMeetingRooms(vector<Interval> &inter) {
        if(inter.empty())
            return 0;
        int n = inter.size(), res = 0, count = 0;
        vector<pair<int, char>> arr(2 * n);

        for(int i = 0; i < n; i++)
            arr[i] = {inter[i].start, 's'};
        for(int i = n; i < 2 * n; i++)
            arr[i] = {inter[i - n].end, 'e'};
        sort(arr.begin(), arr.end(), [&](pair<int, char> &a, pair<int, char> &b){
            return (a.first != b.first ? a.first < b.first : a.second < b.second);
        });
        for(int i = 0; i < 2 * n; i++){
            if(arr[i].second == 's')
                count++;
            else
                count--;
            res = max(res, count);
        }
        return res;
    }
};
