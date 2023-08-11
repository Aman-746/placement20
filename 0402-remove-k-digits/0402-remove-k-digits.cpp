class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k>0){
            st.pop();
            k--;
        }
        
        string temp ="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        
        reverse(temp.begin(),temp.end());
        
        int ind;
        for(ind=0;ind<temp.size();ind++){
            if(temp[ind]!='0') break;
        }
        
        string ans="";
        for(int i=ind;i<temp.size();i++) ans+=temp[i];
        if(ans=="") ans="0";
        return ans;
    }
};