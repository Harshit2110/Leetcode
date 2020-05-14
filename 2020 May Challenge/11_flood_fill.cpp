class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        if(image[sr][sc] == newColor ) // there will be no change in the image
            return image;

        int row = image.size();
        int col = image[0].size();

        int oldColor = image[sr][sc];

        //make dfs call
        dfs(image, sr, sc, oldColor, newColor, row, col);

        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int oldC, int newC, int row, int col){

        if(i >= row || i < 0 || j >= col || j < 0)
            return;
        else if(image[i][j] != oldC)
            return;

        image[i][j] = newC;

        //make recursive call in four directions
        dfs(image, i-1, j, oldC, newC, row, col); //top
        dfs(image, i, j+1, oldC, newC, row, col); //right
        dfs(image, i+1, j, oldC, newC, row, col); //down
        dfs(image, i, j-1, oldC, newC, row, col); //left
    }
};
