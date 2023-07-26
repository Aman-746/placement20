//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // sort Jobs according to the profit
        vector<int>ans;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({arr[i].profit,arr[i].dead});
        }
        sort(vp.begin(),vp.end());
        vector<int>vis(n,0);
        int total=0;
        int jobs=0;
        for(int i=n-1;i>=0;i--){
            int pr=vp[i].first;
            int dl=vp[i].second;
            int ind=dl-1;
            while(ind>=0 && vis[ind]==1){
                ind--;
            }
            if(ind<0) continue;
            else{
                vis[ind]=1;
                total+=pr;
                jobs++;
            }
        }
        ans.push_back(jobs);
        ans.push_back(total);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends