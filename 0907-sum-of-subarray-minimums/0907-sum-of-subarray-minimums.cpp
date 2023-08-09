class Solution {
public:
    // find first next lesser element index (NLE) and previos lesser element index
    // (PLE) for each element of array
    // the subarrays in which arr[i] will be the minimum is (i-PLE)*(NLE-i)
    // and the sum will be arr[i]*((i-PLE)*(NLE-i));
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();
        int NLE[n],PLE[n];
        stack<int>st1,st2;
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[st1.top()]>arr[i]) st1.pop();
            if(st1.empty()) PLE[i]=-1;
            else PLE[i]=st1.top();
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>=arr[i]) st2.pop();
            if(st2.empty()) NLE[i]=n;
            else NLE[i]=st2.top();
            st2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // ans=(long)(ans+(arr[i]*(i-PLE[i])*(NLE[i]-i)));
            long long prod=((i-PLE[i])*(NLE[i]-i))%mod;
            prod=(prod*arr[i])%mod;
            ans=(ans+prod)%mod;
        }
        return ans%mod;
    }
};