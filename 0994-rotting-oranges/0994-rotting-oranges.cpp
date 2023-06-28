class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // int time=0;
        // ((row,col),time)
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        int ans=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            
            if(row>0 && grid[row-1][col]==1 && !vis[row-1][col]){
                vis[row-1][col]=1;
                q.push({{row-1,col},time+1});
                grid[row-1][col]=2;
            }
            if(row<m-1 && grid[row+1][col]==1 && !vis[row+1][col]){
                vis[row+1][col]=1;
                q.push({{row+1,col},time+1});
                grid[row+1][col]=2;
            }
            if(col>0 && grid[row][col-1]==1 && !vis[row][col-1]){
                vis[row][col-1]=1;
                q.push({{row,col-1},time+1});
                grid[row][col-1]=2;
            }
            if(col<n-1 && grid[row][col+1]==1 && !vis[row][col+1]){
                vis[row][col+1]=1;
                q.push({{row,col+1},time+1});
                grid[row][col+1]=2;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans;
    }
};