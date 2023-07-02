class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0;
        int prev=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,max(prev2+nums[i],prev));
            prev2=prev;
            prev=ans;
        }
        return prev;
    }
};