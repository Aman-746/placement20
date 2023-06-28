class Solution {
public:
    
    void dfs(int start, int n, vector<int>& vis, vector<vector<int>>& isConnected){
        vis[start]=1;
        for(int i=0;i<n;i++){
            if(isConnected[start-1][i]==1 && !vis[i+1]) dfs(i+1,n,vis,isConnected);
        }
    }
        
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n+1,0);
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(!vis[i]){
                ans++;
                dfs(i,n,vis,isConnected);
            }
        }
        return ans;
    }
};