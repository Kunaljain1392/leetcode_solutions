class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        vector<bool> temp(n + 1, false);

        for (int num : nums) {
            temp[num] = true;
        }

        for (int i = 0; i <= n; i++) {
            if (!temp[i]) {
                return i;
            }
        }

        return -1;
    }
};