class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open,star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(open.empty()){
                    if(star.empty()) return false;
                    else star.pop();
                }
                else open.pop();
            }
        }
        while(!open.empty()){
            if(star.empty()) return false;
            int starInd=star.top();
            if(starInd>open.top()){
                open.pop();
                star.pop();
            }
            else return false;
        }
        return true;
    }
};