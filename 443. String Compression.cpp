class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j, count = 1;

        chars.push_back('-');
        for(j = 1; j < chars.size(); j++){
            if(chars[i] == chars[j]){
                count++;
            }
            else{
                i++;
                if(count != 1){
                    string temp = to_string(count);
                    for(int k = 0; k < temp.size(); k++)
                        chars[i++] = temp[k];
                }
                chars[i] = chars[j];
                count = 1;
            }
        }
        return i;
    }
};
