class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size()-1;
        int cnt = 0;
        while(l<=r) {
            if(nums[r] == val) {
                r--;
                cnt++;
            } else if( nums[l] == val) {
                swap(nums[l],nums[r]);
                l++;
                r--;
                cnt++;
            } else {
                l++;
            }
            
        }
        return nums.size()-cnt;
      
    }
};