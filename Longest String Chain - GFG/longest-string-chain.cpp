//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool predecessor(string a, string b){
        if(a.size()!=b.size()-1) return false;
        for(int i=0;i<b.size();i++){
            string temp=b;
            temp.erase(temp.begin()+i);
            if(a==temp) return true;
        }
        return false;
    }
    
    // bool comp(string &a, string &b){
    //     return a.size()<b.size();
    // }
    
    int longestChain(int n, vector<string>& words) {
        // Code here
        // sort(words.begin(),words.end(),comp);
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        vector<int>dp(n,1);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(predecessor(words[j],words[i])) dp[i]=max(1+dp[j],dp[i]);
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends