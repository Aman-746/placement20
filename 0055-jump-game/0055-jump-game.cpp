class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxVisit=0;
        for(int i=0;i<n;i++){
            if(maxVisit<i) continue;
            if(i+nums[i]>maxVisit) maxVisit=i+nums[i];
            if(maxVisit>=n-1) return true;
        }
        return false;
    }
};