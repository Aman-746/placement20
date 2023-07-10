class Solution {
public:
    
    // simple recursion we can use here because the string length is very small
    // just do the partition at each index and do the same for the right string using
    // recursion , also check if the string is beautiful or not
    
    // this function will check if curr is power of 5 or not and also doesn't start 
    // with '0'
    bool isBeautiful(string curr){
        if(curr[0]=='0') return false;
        int val=0;
        for(int i=0;i<curr.size();i++){
            val*=2;
            val+=(curr[i]=='1'?1:0);
        }
        int num=1;
        while(num<=val){
            if(num==val) return true;
            num*=5;
        }
        return false;
    }
    
    int solve(string s){
        if(s.size()==0) return 0;
        int ans=20;
        for(int i=0;i<s.size();i++){
            string curr=s.substr(0,i+1);
            if(isBeautiful(curr)) ans=min(ans,1+solve(s.substr(i+1)));
        }
        return ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        int ans=solve(s);
        if(ans>15) return -1;
        return ans;
    }
};