class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> um;
        int res = 0;

        int i = 0, j, count = 0;
        for(j = 0; j < tree.size(); j++){
            um[tree[j]]++;

            if(um[tree[j]] == 1)
                count++;
            if(count == 3){
                while(um[tree[i]] != 1){
                    um[tree[i]]--;
                    i++;
                }
                um[tree[i]]--;
                i++;
                count--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
