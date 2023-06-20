class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // 3 variables index, buy, cap=k
        int n=prices.size();
        int dp[n+1][2][k+1];
        
        // two base cases which is if(ind==n || cap==0) return 0;
        for(int ind=0;ind<=n;ind++){
            for(int buy=0;buy<=1;buy++){
                for(int cap=0;cap<=k;cap++){
                    if(ind==n) dp[ind][buy][cap]=0;
                    if(cap==0) dp[ind][buy][cap]=0;
                }
            }
        }
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy==1) dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                    else dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][k];
    }
};