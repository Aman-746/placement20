class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
	    for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dist[i][j]=0;
            }
        }

        // i to j via k
        // these tree loops will help us to 
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        // count will tell us that from that node how many destinations are there where 
        // we can reach with lesser or equal distance than given threshold distance
        vector<int>count(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold) count[i]++;
            }
        }

        int ans=INT_MAX;
        int node;
        for(int i=0;i<n;i++){
            if(count[i]<=ans){
                ans=count[i];
                node=i;
            }
        }

        return node;
    }
};