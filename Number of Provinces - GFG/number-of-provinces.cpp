//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int start, int V, vector<int>& vis, vector<vector<int>>& adj){
        vis[start]=1;
        for(int i=0;i<V;i++){
            if(adj[start-1][i]==1 && !vis[i+1]) dfs(i+1,V,vis,adj);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>vis(V+1,0);
        int cnt=0;
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,V,vis,adj);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends