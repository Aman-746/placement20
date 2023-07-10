class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++) adj[times[i][0]].push_back({times[i][1],times[i][2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        // time,node
        pq.push({0,k});
        
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            // t is time to reach from source to current node
            int t=it.first;
            int node=it.second;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int cost=it.second;
                if(t+cost<time[adjNode]){
                    time[adjNode]=t+cost;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(time[i]==INT_MAX) return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};