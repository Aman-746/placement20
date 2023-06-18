class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0) dp[i][j]=triangle[i][j]+dp[i-1][j];
                else if(j==i) dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                else dp[i][j]=triangle[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++) ans=min(ans,dp[n-1][j]);
        return ans;
    }
};


// 2
// 3 4
// 6 5 7
// 4 1 8 3

// 2
// 5  6
// 11 10 13
// 15 11 18 16