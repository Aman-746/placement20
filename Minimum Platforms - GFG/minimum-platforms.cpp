//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    // void solve(int i, int n, vector<int>& vis, vector<pair<int,int>>& vp){
    //     vis[i]=1;
    //     int preDepart=vp[i].first;
    //     for(int j=i+1;j<n;j++){
    //         if(vis[j]==1) continue;
    //         int arrival=vp[j].second;
    //         int depart=vp[j].first;
    //         if(arrival>preDepart){
    //             vis[j]=1;
    //             preDepart=depart;
    //         }
    //     }
    // }
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int plate_needed=1;
    	int res=1;
    	int i=1,j=0;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        plate_needed++;
    	        i++;
    	    }
    	    else{
    	        plate_needed--;
    	        j++;
    	    }
    	    if(plate_needed>res) res=plate_needed;
    	}
    	return res;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends