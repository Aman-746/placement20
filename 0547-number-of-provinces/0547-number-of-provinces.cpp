class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        queue<int>q;
        int nodeVisited=0;
        int ans=0;
        for(int j=0;j<n;j++){
            if(!vis[j]){
                ans++;
                vis[j]=1;
                q.push(j);
                while(!q.empty()){
                    nodeVisited++;
                    int node=q.front();
                    q.pop();
                    for(int i=0;i<n;i++){
                        if(isConnected[node][i]==1 && vis[i]==0){
                            vis[i]=1;
                            q.push(i);
                        }
                    }
                }
            }
        }
        return ans;
    }
};