class Solution {
public:
    
    int f(int i, char first, char last, vector<string>& words,vector<vector<vector<int>>>& dp){
        if(i>=words.size()) return 0;
        if(dp[i][first-'a'][last-'a']!=-1) return dp[i][first-'a'][last-'a'];
        int size=words[i].size();
        int res=INT_MAX;
        
        // prev+words[i]
        if(last==words[i].front()) res=min(res,size-1+f(i+1,first,words[i].back(),words,dp));
        else res=min(res,size+f(i+1,first,words[i].back(),words,dp));
         
        // words[i]+prev
        if(words[i].back()==first) res=min(res,size-1+f(i+1,words[i].front(),last,words,dp));
        else res=min(res,size+f(i+1,words[i].front(),last,words,dp));
        
        return dp[i][first-'a'][last-'a']=res;
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<vector<int>>>dp(words.size(),vector<vector<int>>(26,vector<int>(26,-1)));
        return words[0].size()+f(1,words[0].front(),words[0].back(),words,dp);
    }
};