//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int>dp(n,1),hash(n);
        int maxInd=0;
        int maxi=INT_MIN;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prevInd=0;prevInd<ind;prevInd++){
                if(arr[ind]>arr[prevInd] && dp[ind]<1+dp[prevInd]){
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
        ans.push_back(arr[maxInd]);
        while(maxInd!=hash[maxInd]){
            ans.insert(ans.begin(),arr[hash[maxInd]]);
            maxInd=hash[maxInd];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends