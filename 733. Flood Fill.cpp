class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};
        int target = image[sr][sc];

        if(target == newColor)
            return image;
        image[sr][sc] = newColor;
        for(int i = 0; i < 4; i++){
            int _x = sr + xMove[i];
            int _y = sc + yMove[i];
            if(0 <= _x && _x < image.size() && 0 <= _y && _y < image[_x].size() && image[_x][_y] == target)
                floodFill(image, _x, _y, newColor);
        }
        return image;
    }
};
