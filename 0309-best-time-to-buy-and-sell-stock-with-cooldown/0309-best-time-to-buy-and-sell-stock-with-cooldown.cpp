class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // two variables here index and buy
        int n=prices.size();
        // int dp[n+2][2];
        // for(int ind=0;ind<=n;ind++){
        //     for(int buy=0;buy<=1;buy++){
        //         if(ind==n || ind==n+1) dp[ind][buy]=0;
        //     }
        // }
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1) dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                else dp[ind][buy]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
};