class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,bool> mp;
        for(int i=1;i<=nums.size()+1;i++) {
            mp[k*i] = false;
        }
        for(int i:nums) {
            if(mp.find(i) != mp.end()) {
                mp[i] = true;
            }
        }
        for(auto i:mp) {
            if(i.second == false) {
                return i.first;
            }
        }
        return -1;
    }
};