class Solution {
public:
    int trap(vector<int>& height) {
        // create suffix max array and prefix max array
        int n=height.size();
        vector<int>preMax(n,0);
        preMax[0]=height[0];
        for(int i=1;i<n;i++) preMax[i]=max(height[i],preMax[i-1]);
        vector<int>suffMax(n,0);
        suffMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--) suffMax[i]=max(height[i],suffMax[i+1]);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(preMax[i],suffMax[i])-height[i]);
        }
        return ans;
    }
};