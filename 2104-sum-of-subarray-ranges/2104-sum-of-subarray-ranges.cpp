class Solution {
public:
    // koi number (nums[i]) kitne subarray ke liye minimum hoga aur kitne subarray ke liye 
    // maximum hoga.
    // suppose that nums[i] will be minimum for p subarrays
    // and nums[i] will be maximum for q subarrays
    // then nums[i] will contribute this much to answer q.nums[i]-p*nums[i];
    
    // PLE previous lesser element
    // NLE next lesser element
    // PGE previous greater element
    // NGE next greater element
    
    // for finding the no. of subarray for which nums[i] will be minimum we will have
    // to find PLE and NLE index, then total no. of subarray will be (NLE-i)*(i-PLE)
    
    // for finding the no. of subarray for which nums[i] will be maximum we will have
    // to find PGE and NGE index, then total no. of subarray will be (NGE-i)*(i-PGE)
    
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>ple(n,-1);
        stack<int>st1;
        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[st1.top()]>nums[i]) st1.pop();
            if(!st1.empty()) ple[i]=st1.top();
            st1.push(i);
        }
        
        vector<int>nle(n,n);
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()]>=nums[i]) st2.pop();
            if(!st2.empty()) nle[i]=st2.top();
            st2.push(i);
        }
        
        vector<int>pge(n,-1);
        stack<int>st3;
        for(int i=0;i<n;i++){
            while(!st3.empty() && nums[st3.top()]<nums[i]) st3.pop();
            if(!st3.empty()) pge[i]=st3.top();
            st3.push(i);
        }
        
        vector<int>nge(n,n);
        stack<int>st4;
        for(int i=n-1;i>=0;i--){
            while(!st4.empty() && nums[st4.top()]<=nums[i]) st4.pop();
            if(!st4.empty()) nge[i]=st4.top();
            st4.push(i);
        }
        
        long long sum_mini=0;
        long long sum_maxi=0;
        for(int i=0;i<n;i++){
            long long prod1 = (i-ple[i])*(nle[i]-i);
            sum_mini-=nums[i]*prod1;
            long long prod2= (i-pge[i])*(nge[i]-i);
            sum_maxi+=nums[i]*prod2;
        }
        return sum_maxi+sum_mini;
    }
};