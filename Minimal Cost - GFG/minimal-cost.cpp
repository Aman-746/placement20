//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,0);
        if(k>=n) k=n-1;
        dp[0]=0;
        int j=0;
        for(int i=1;i<n;i++){
            int mini=INT_MAX;
                for((i<=k ? j=0 : j=i-k); j<i; j++){
                    if(dp[j]+abs(height[i]-height[j])<mini) mini=dp[j]+abs(height[i]-height[j]);
                dp[i]=mini;
            }
        }
        // for(int i=1;i<=k;i++){
        //     int mini=INT_MAX;
        //     for(int j=0;j<i;j++){
        //         if(dp[j]+abs(height[i]-height[j])<mini) mini=dp[j]+abs(height[i]-height[j]);
        //     }
        //     dp[i]=mini;
        // }
        // for(int i=k+1;i<n;i++){
        //     int mini=INT_MAX;
        //     for(int j=i-k;j<i;j++){
        //         if(dp[j]+abs(height[i]-height[j])<mini) mini=dp[j]+abs(height[i]-height[j]);
        //     }
        //     dp[i]=mini;
        // }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends