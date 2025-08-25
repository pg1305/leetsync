class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();

    long long S_actual = 1LL * n * (n + 1) / 2;
    long long Q_actual = 1LL * n * (n + 1) * (2LL * n + 1) / 6;

    long long S = 0, Q = 0;
    for (int x : nums) {
        S += x;
        Q += 1LL * x * x;
    }

    long long diff1 = S - S_actual;       // A - B
    long long diff2 = Q - Q_actual;       // A^2 - B^2

    long long sumAB = diff2 / diff1;      // A + B
    int A = (diff1 + sumAB) / 2;
    int B = A - diff1;

    return {A, B};
}
};