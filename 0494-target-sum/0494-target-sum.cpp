class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        // target is basiclly difference of two subset here
        if((sum+target)%2!=0 || (sum+target<0)) return 0;
        int req_sum=(sum+target)/2;
        int dp[n+1][req_sum+1];
        dp[0][0]=1;
        for(int i=1;i<=req_sum;i++) dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=req_sum;j++){
                if(nums[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][req_sum];
    }
};