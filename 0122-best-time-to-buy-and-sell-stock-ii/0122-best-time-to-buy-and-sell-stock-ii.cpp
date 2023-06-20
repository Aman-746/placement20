class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // buy on lowest and sell on highest
        int lowest=prices[0];
        int highest=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]<prices[i-1]){
                profit+=(highest-lowest);
                lowest=prices[i];
                highest=prices[i];
            }
            else{
                highest=prices[i];
            }
            
        }
        if(highest>lowest) profit+=(highest-lowest);
        return profit;
    }
};