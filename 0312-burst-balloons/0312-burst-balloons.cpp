class Solution {
public:
    
    int solve(vector<vector<int>>& dp, vector<int>& nums, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxCost=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost=nums[i-1]*nums[k]*nums[j+1]+solve(dp,nums,i,k-1)+solve(dp,nums,k+1,j);
            maxCost=max(cost,maxCost);
        }
        return dp[i][j]=maxCost;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(dp,nums,1,n);
    }
};