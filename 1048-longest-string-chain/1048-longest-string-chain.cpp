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
    
    int longestStrChain(vector<string>& words) {
        
        // sort(words.begin(),words.end(),cmp);
        
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
        
        int n=words.size();
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