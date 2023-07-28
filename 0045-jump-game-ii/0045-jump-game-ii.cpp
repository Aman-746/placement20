class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int minJumpTillMaxVis=0;
        int maxVis=0;
        vector<int>jump(n,INT_MAX);
        jump[0]=0;
        for(int i=0;i<n;i++){
            if(i+nums[i]>maxVis){
                for(int j=maxVis+1;j<=min(n-1,i+nums[i]);j++) jump[j]=min(jump[j],1+jump[i]);
                maxVis=i+nums[i];
            }
        }
        return jump[n-1];
    }
};