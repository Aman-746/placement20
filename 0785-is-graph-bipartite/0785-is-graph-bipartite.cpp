class Solution {
public:
    // here instead of visited array we will use color array
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        queue<int>q;
        vector<int>color(m,-1);
        for(int i=0;i<m;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(color[it]==-1){
                            color[it]=!color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]) return false;
                    }
                }
            }
        }
        
        return true;
    }
};