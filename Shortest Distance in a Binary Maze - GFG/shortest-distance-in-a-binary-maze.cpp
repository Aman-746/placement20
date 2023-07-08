//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        // // source row and source column
        // int sr=source.first;
        // int sc=source.second;
        // // destination row and destination column
        // int dtr=
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});
        
        // dr is delta row and dc is delta column
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int distance=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==destination.first && col==destination.second) return distance;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && dist[nr][nc]>1+distance){
                    dist[nr][nc]=1+distance;
                    q.push({dist[nr][nc],{nr,nc}});
                }
                
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends