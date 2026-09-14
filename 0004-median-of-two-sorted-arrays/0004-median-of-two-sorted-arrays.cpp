class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> result;
        while(i<n && j < m) {

            if(nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while(j<m) {
            result.push_back(nums2[j]);
            j++;
        }

        while(i<n) {
            result.push_back(nums1[i]);
            i++;
        }

        if((m+n)%2==0) {
            int idx1 = (m+n)/2;
            int idx2 = idx1-1;
            return (result[idx1] + result[idx2])/2.0;
        }

        return result[(m+n)/2];
    }
};