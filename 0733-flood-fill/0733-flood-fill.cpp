class Solution {
public:
    
    void dfs(int baseColor, int sr, int sc, int color,vector<vector<int>>& image){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=baseColor) return;
        image[sr][sc]=color;
        dfs(baseColor,sr-1,sc,color,image);
        dfs(baseColor,sr+1,sc,color,image);
        dfs(baseColor,sr,sc-1,color,image);
        dfs(baseColor,sr,sc+1,color,image);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int baseColor=image[sr][sc];
        if(baseColor==color) return image;
        dfs(baseColor,sr,sc,color,image);
        return image;
    }
};