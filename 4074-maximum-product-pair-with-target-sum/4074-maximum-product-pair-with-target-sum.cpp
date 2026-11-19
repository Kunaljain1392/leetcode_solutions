class Solution {
public:
    vector<int> maxProductPair(vector<int>& arr, int target) {
        unordered_map<int, int> need;
        vector<int> ans = {-1,-1};
        int mxprd = INT_MIN;
        for(int i=0;i<arr.size();i++) {
            int tmp = target - arr[i];
            if(need.find(tmp) != need.end() && arr[i] != tmp) {
                int x,y;
                if(arr[i] > tmp) {
                    x = i;
                    y = need[tmp];
                } else {
                    x = need[tmp];
                    y = i;
                }
                int prd = arr[x]*arr[y];
                if(prd > mxprd) {
                    mxprd = prd;
                    ans[0] = x;
                    ans[1] = y;
                }
            }
            need[arr[i]] = i;
        }
        return ans;
    }
};