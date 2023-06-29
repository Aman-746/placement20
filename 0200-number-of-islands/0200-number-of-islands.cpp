class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col]=1;
        
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && !vis[nr][nc]) dfs(nr,nc,vis,grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};