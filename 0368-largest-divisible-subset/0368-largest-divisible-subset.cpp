class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int maxInd=0;
        int maxi=INT_MIN;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prevInd=0;prevInd<ind;prevInd++){
                if(nums[ind]%nums[prevInd]==0 && dp[ind]<1+dp[prevInd]){
                    dp[ind]=1+dp[prevInd];
                    hash[ind]=prevInd;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                maxInd=ind;
            }
        }
        vector<int>ans;
        ans.push_back(nums[maxInd]);
        while(maxInd!=hash[maxInd]){
            ans.insert(ans.begin(),nums[hash[maxInd]]);
            maxInd=hash[maxInd];
        }
        return ans;
    }
};