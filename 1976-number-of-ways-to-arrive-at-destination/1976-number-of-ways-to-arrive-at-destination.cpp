class Solution {
public:
    // used priority queue but wrong answer because i think if the same node 
    int countPaths(int n, vector<vector<int>>& roads) {
        
        long long mod=1e9+7;
        
        // adjacency list
        vector<pair<long long,long long>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        // making priority queue to store {distance,node}
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        
        vector<long long>minDist(n,1e18),ways(n,0);
        minDist[0]=0;
        ways[0]=1;
        // int ans=0;
        
        while(!pq.empty()){
            long long doori=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long dist=it.second;
                if(dist+doori<minDist[adjNode]){
                    minDist[adjNode]=dist+doori;
                    pq.push({minDist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dist+doori==minDist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};