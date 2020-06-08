class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = min(C, G), b = max(A, E), c = min(D, H), d = max(B, F);
        int common;
        if(a <= b || c <= d)
            common =  0;
        else
            common = (a - b) * (c - d);
        return (C - A) * (D - B) - common + (G - E) * (H - F) ;
    }
};
