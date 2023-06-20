//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

        
        
    int solve(vector<vector<int>>& dp,int arr[], int i, int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp_ans=solve(dp,arr,i,k)+solve(dp,arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,temp_ans);
        }
        return dp[i][j]=ans;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return solve(dp,arr,1,N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends