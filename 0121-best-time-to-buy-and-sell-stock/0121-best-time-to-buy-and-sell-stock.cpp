class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxTillNow=INT_MIN;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            maxTillNow=max(maxTillNow,prices[i]);
            ans=max(ans,maxTillNow-prices[i]);
        }
        return ans;
    }
};