class Solution {
public:
    int solve(vector<int>& heights){
        int n=heights.size();
        
        stack<int>st1;
        vector<int>PLE(n,-1);
        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i]) st1.pop();
            if(!st1.empty()) PLE[i]=st1.top();
            st1.push(i);
        }
        
        stack<int>st2;
        vector<int>NLE(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i]) st2.pop();
            if(!st2.empty()) NLE[i]=st2.top();
            st2.push(i);
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int width=(NLE[i]-1)-(PLE[i]+1)+1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        // for each row create a height array
        int rl=matrix.size();
        int cl=matrix[0].size();
        vector<int>heights(cl,0);
        int res=0;
        for(int i=0;i<rl;i++){
            // int maxi=0;
            for(int j=0;j<cl;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int maxi=solve(heights);
            res=max(res,maxi);
        }
        return res;
    }
};