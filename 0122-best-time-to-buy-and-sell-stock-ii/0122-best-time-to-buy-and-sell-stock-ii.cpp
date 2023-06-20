class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // buy on lowest and sell on highest
        // maintain highest and lowest price at each index and price goes down then find the 
        // calculate the profit that will give the profit till (i-1)th day
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