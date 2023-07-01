class Solution {
public:
    
    // bool compare(string s, string t){
    //     if(s.size()!=t.size()) return false;
    //     int cnt=0;
    //     for(int i=0;i<s.size();i++){
    //         if(s[i]!=t[i]) cnt++;
    //     }
    //     if(cnt==1) return true;
    //     return false;
    // }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // wordList.insert(wordList.begin(),beginWord);
        // int n=wordList.size();
        // vector<int>adj[n];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(compare(wordList[i],wordList[j])) adj[i].push_back(j);
        //     }
        // }
        
        // vector<int>vis(n,0);
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord); // erase here representing visited string
        // q.push({0,1});
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord) return step;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a'; c<='z'; c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
            
        }
        return 0;
    }
};