class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int evenCnt = 0;
        int oddCnt = 0;

        for(int i:nums1) {
            mini = min(mini,i);
            if(!(i&1)) {
                evenCnt++;
            }
        }
        if(mini&1) {
            return true;
        }
        if(!(mini&1) && evenCnt == nums1.size() ) {
            return true;
        }

        return false;
    }
};