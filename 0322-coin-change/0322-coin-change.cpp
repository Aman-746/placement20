class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        int dp[n+1][amount+1];
        memset(dp,0,sizeof dp);
        int maxi=INT_MAX-1;
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=amount;j++) dp[0][j]=maxi;
        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0){
                dp[1][j]=j/coins[0];
            } 
            else dp[1][j]=maxi;
        }
        for(int i=2;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
        }
        return dp[n][amount]==maxi ? -1 : dp[n][amount];
    }
};