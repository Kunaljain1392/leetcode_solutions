class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int x = n;
        while(x!=0) {
            int d = x%10;
            x = x/10;
            sum += d;
            prod *= d;
        }
        int num = sum+prod;
        return (n%num == 0);
    }
};