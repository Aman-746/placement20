//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  // visited and pathVisited two array will be needed to check
  // when we will traverse the dfs for the first time then pathVis[node] will be 1 and after all dfs call when 
  // we come back then we will make pathVis[node]=0... if the adjacent node is in the same path means we are going
  // in the cycle
  bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]){
      vis[node]=1;
      pathVis[node]=1;
      for(auto it:adj[node]){
          // if not visited till now
          if(!vis[it]){
              if(dfs(it,vis,pathVis,adj)) return true;
          }
          // if in the same path means there is cycle
          else if(pathVis[it]==1) return true;
      }
      pathVis[node]=0;
      return false;
  }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends