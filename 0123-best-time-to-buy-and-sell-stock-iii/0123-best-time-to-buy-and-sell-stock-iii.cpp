class Solution {
public:
    
    int f(vector<vector<vector<int>>>& dp,vector<int>& prices, int index, int buy, int cap){
        if(index==prices.size() || cap==0) return 0;
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        if(buy==1){
            return dp[index][buy][cap]=max(-prices[index]+f(dp,prices,index+1,0,cap),0+f(dp,prices,index+1,1,cap));
        }
        return dp[index][buy][cap]=max(prices[index]+f(dp,prices,index+1,1,cap-1),f(dp,prices,index+1,0,cap));
    }
    
    int maxProfit(vector<int>& prices) {
        // 3d vector ind/buy/cap;
        // ind-n, buy-0/1, cap-0/1/2
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(dp,prices,0,1,2);
    }
};