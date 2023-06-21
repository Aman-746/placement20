//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool palindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(vector<int>& dp, string s, int i, int j){
        if(i>=j || palindrome(s,i,j)==true) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int minPart=INT_MAX;
        
        for(int k=i;k<=j-1;k++){
            if(palindrome(s,i,k)){
                int partition=1+solve(dp,s,k+1,j);
                minPart=min(partition,minPart);
            }
        }
        return dp[i]=minPart;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n+1,-1);
        return solve(dp,str,0,n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends