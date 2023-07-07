class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        int r=-1;
        multiset<int>all;
        
        for(int l=0;l<n;l++){
            if(r<l){
                all.insert(nums[l]);
                r=l;
            }
            while(r<n && (*all.rbegin() - *all.begin()<=2)){
                r++;
                if(r<n) all.insert(nums[r]);
            }
            res+=(r-l);
            all.erase(all.find(nums[l]));
        }
        
        return res;
    }
};