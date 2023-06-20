class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minTillNow=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            minTillNow=min(minTillNow,prices[i]);
            ans=max(ans,prices[i]-minTillNow);
        }
        return ans;
    }
};