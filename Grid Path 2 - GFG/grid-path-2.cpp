//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        // vector<vector<int,int>>dp(n,vector<int>(m,0));
        int mod=1e9+7;
        int dp[n][m];
        memset(dp,0,sizeof dp);
        bool stoneCol=false;
        int i=0,j=0;
        for(i;i<n;i++){
            if(grid[i][0]==0) dp[i][0]=1;
            else{
                stoneCol=true;
                break;
            }
        }
        if(stoneCol){
            for(int i1=i;i1<n;i1++) dp[i1][0]=0;
        }
        
        bool stoneRow=false;
        for(j;j<m;j++){
            if(grid[0][j]==0) dp[0][j]=1;
            else{
                stoneRow=true;
                break;
            }
        }
        if(stoneRow){
            for(int j1=j;j1<m;j1++) dp[0][j1]=0;
        }
        
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(grid[i][j]==1) dp[i][j]=0;
                else if(dp[i-1][j]==0 && dp[i][j-1]==0) dp[i][j]=0;
                else if(dp[i-1][j]!=0 && dp[i][j-1]!=0) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                else if(dp[i-1][j]!=0) dp[i][j]=(dp[i-1][j])%mod;
                else dp[i][j]=(dp[i][j-1])%mod;
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends