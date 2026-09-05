class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        vector<int> sufixmin(nums.size());

        for(int i=nums.size()-1;i>=0;i--) {
            mini = min(mini,nums[i]);
            sufixmin[i] = mini;
        }

        for(long long  int i=0;i<nums.size();i++) {
            
            if( maxi < nums[i]) {
                maxi = nums[i];
            }

            int score = maxi - sufixmin[i];
            
            if(score <= k) {
                return i;
            }
        }
        return -1;
    }
};