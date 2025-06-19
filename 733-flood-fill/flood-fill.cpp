class Solution {
private:
    void dfs(vector<vector<int>> &image, int sr, int sc, int orgcolor, int color){
        int n = image.size();
        int m = image[0].size();
        if(sr<0 || sr>=n || sc<0 || sc>=m )
        return ;
        if(orgcolor==color)
        return;
        if(image[sr][sc]!=orgcolor)
        return ;
        image[sr][sc] = color;
        dfs(image, sr+1, sc, orgcolor, color);
        dfs(image, sr-1, sc, orgcolor, color);
        dfs(image, sr, sc+1, orgcolor, color);
        dfs(image, sr, sc-1, orgcolor, color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgcolor = image[sr][sc];
        dfs(image, sr, sc, orgcolor, color);
        return image;
    }
};