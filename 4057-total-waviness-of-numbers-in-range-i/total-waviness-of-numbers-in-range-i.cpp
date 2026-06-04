class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        vector<int> digits(10);
        for (int i=num1; i<=num2; i++) {
            int n = i;
            int sz = 0;
            while (n!=0) {
                digits[sz++] = (n % 10);
                n /= 10;
            }
            for (int i=1; i<sz-1; i++) {
                if (digits[i] > digits[i-1] && digits[i] > digits[i+1]) ans++;
                else if (digits[i] < digits[i-1] && digits[i] < digits[i+1]) ans++;
            }
        }   
        return ans;
    }
};