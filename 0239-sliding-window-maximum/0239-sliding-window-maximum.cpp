class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // store number in deque in decreasing order and maintain the window everytime
        // means if front of deque is out of current window then pop from front.
        // and then if back of deque is lesser than current number then pop from last 
        // untill bigger number in deque arrives.
        
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};