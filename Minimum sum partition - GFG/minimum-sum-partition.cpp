//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=accumulate(arr,arr+n,0);
	    int total=sum;
	    if(sum%2) sum++;
	    sum/=2;
	    int dp[n+1][sum+1];
	    for(int j=0;j<=sum;j++) dp[0][j]=0;
	    for(int i=0;i<=n;i++) dp[i][0]=1;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
	            else dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	        }
	    }
	    int num;
	    for(int j=0;j<=sum;j++){
	        for(int i=0;i<=n;i++){
	            if(dp[i][j]==1) num=j;
	        }
	    }
	   return abs(2*num-total);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends