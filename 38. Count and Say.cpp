class Solution {
public:
    string countAndSay(int n) {
        string a, b;

        a = "1";
        while(n > 1){
            b.erase();
            int i = 0, count;

            while(i < a.length()){
                count = 1;
                while(a[i] == a[i + 1])
                    i++, count++;
                b += (to_string(count) + a[i]);
                i++;
            }
            swap(a, b);
            n--;
        }
        return a;
    }
};
