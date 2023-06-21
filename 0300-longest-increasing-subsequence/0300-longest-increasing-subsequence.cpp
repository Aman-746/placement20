class Solution {
public:
    int solve(vector<int>& nums, int ind, int prevInd,int n,vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        // not pick case 
        int len= 0+solve(nums,ind+1,prevInd,n,dp);
        // pick case
        if(prevInd==-1 || nums[ind]>nums[prevInd]){
            len=max(len,1+solve(nums,ind+1,ind,n,dp));
        }
        return dp[ind][prevInd+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,n,dp);
    }
};