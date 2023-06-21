class Solution {
public:
    // recursive + memoization
    
    int solve(vector<vector<int>>& dp,vector<int>& cuts, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minCost=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=(cuts[j+1]-cuts[i-1])+solve(dp,cuts,i,k-1)+solve(dp,cuts,k+1,j);
            minCost=min(cost,minCost);
        }
        return dp[i][j]=minCost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        // 0 1 3 4 5 7
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return solve(dp,cuts,1,c);
    }
};