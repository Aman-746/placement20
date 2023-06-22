class Solution {
public:
    int solve(vector<int>& dp, vector<int>& arr, int ind, int k){
        int n=arr.size();
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        for(int i=ind;i<min(ind+k,n);i++){
            len++;
            maxi=max(maxi,arr[i]);
            int sum=len*maxi+solve(dp,arr,i+1,k);
            maxAns=max(maxAns,sum);
        }
        return dp[ind]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(dp,arr,0,k);
    }
};