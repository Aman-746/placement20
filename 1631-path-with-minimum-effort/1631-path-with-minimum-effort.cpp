class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>diff(m,vector<int>(n,1e9));
        diff[0][0]=0;
        
        // difference row col
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        // queue<pair<int,pair<int,int>>>q;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int difference=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==m-1 && col==n-1) return difference;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int newEffort=max(difference,abs(heights[nr][nc]-heights[row][col]));
                    if(newEffort<diff[nr][nc]){
                        diff[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};