class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 1;
        
        int c = 0;
        int n = nums1.size();
        
        vector<vector<int>>dp(n,vector<int>(2,1));
        
        // nums1 = [1,3,2,1], nums2 = [2,2,3,4]
        // dp[i][0] -> ye bata raha hai ki agar hum nums1 ke ith index pr hain to what will be the answer
        // dp[i][1] -> ye bata raha hai ki agar hum nums2 ke ith index pr hain to what will be the answer
        
        for(int i=0;i<n;++i){
            if(i == 0){
                // if we are at the 0th index of nums1 and nums2 then obviously the length is 1 and that will also be non decreasing.
                dp[i][0] = dp[i][1] = 1;
            }
            else{
                //what is the max length if I choose 
                //nums1[i] at ith index
                if(nums1[i]>=nums1[i-1]){
                    dp[i][0] = max(dp[i][0],dp[i-1][0]+1);
                }
                if(nums1[i] >= nums2[i-1]){
                    dp[i][0] = max(dp[i][0] , dp[i-1][1]+1);
                }
                
                //what is the max length if I choose 
                //nums1[i] at ith index
                if(nums2[i]>=nums1[i-1]){
                    dp[i][1] = max(dp[i][1],dp[i-1][0]+1);
                }
                if(nums2[i] >= nums2[i-1]){
                    dp[i][1] = max(dp[i][1] , dp[i-1][1]+1);
                }
                
                ans = max(ans,dp[i][0]);
                ans = max(ans,dp[i][1]);
                
            }
        }
            
      return ans;
    }
};