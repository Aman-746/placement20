class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>res=image;
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==sr && j==sc){
                    res[i][j]=color;
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            if(row>0 && image[row-1][col]==image[row][col] && !vis[row-1][col]){
                vis[row-1][col]=1;
                q.push({row-1,col});
                res[row-1][col]=res[row][col];
            }
            if(row<m-1 && image[row+1][col]==image[row][col] && !vis[row+1][col]){
                vis[row+1][col]=1;
                q.push({row+1,col});
                res[row+1][col]=res[row][col];
            }
            if(col>0 && image[row][col-1]==image[row][col] && !vis[row][col-1]){
                vis[row][col-1]=1;
                q.push({row,col-1});
                res[row][col-1]=res[row][col];
            }
            if(col<n-1 && image[row][col+1]==image[row][col] && !vis[row][col+1]){
                vis[row][col+1]=1;
                q.push({row,col+1});
                res[row][col+1]=res[row][col];
            }
        }
        
        return res;
    }
};