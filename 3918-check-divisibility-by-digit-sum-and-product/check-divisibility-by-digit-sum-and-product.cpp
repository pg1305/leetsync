class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1, org = n;
        while(n > 0){
            int digit = n % 10;
            n /= 10;
            sum += digit;
            product *= digit;
        }
        return org % (sum + product) == 0;
    }
};