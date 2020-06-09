#define pci pair<char, int>
class myComp{
public:
    bool operator()(const pci &a, const pci &b){
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> um;
        priority_queue<pci, vector<pci>, myComp> pq;
        string res = "";

        for(int i = 0; i < S.length(); i++)
            um[S[i]]++;
        for(auto it = um.begin(); it != um.end(); it++)
            pq.push({it->first, it->second});
        while(!pq.empty()){
            pci temp1 = pq.top();
            pq.pop();
            if(pq.empty()){
                if(temp1.second == 1)
                    res += temp1.first;
                else
                    res = "";
                return res;
            }
            pci temp2 = pq.top();
            pq.pop();
            res = res + temp1.first + temp2.first;
            if(temp1.second > 1){
                temp1.second--;
                pq.push(temp1);
            }
            if(temp2.second > 1){
                temp2.second--;
                pq.push(temp2);
            }
        }
        return res;
    }
};
