class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        long long p = prices.size() -1;
        long long d = discounts.size() -1;
        long double ans = 0;
        while(p >= 0 && d >= 0) {
            ans += (prices[p] * (100.0 - discounts[d]))/100.0;
            p--;
            d--;
        }
        while(p>=0) {
            ans += prices[p];
            p--;
        }
        return ans;
        
    }
};