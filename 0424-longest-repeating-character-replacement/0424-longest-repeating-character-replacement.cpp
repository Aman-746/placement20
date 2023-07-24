class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0;
        int res=0;
        int n=s.size();
        int maxChar=0;
        vector<int>cnt(26,0);
        for(int end=0;end<n;end++){
            cnt[s[end]-'A']++;
            if(maxChar<cnt[s[end]-'A']) maxChar=cnt[s[end]-'A'];
            if(end-start+1-maxChar>k){
                cnt[s[start]-'A']--;
                start++;
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};