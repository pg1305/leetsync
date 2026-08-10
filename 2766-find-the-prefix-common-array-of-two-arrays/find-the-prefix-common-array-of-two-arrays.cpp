class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n), frequency(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (++frequency[A[i]] == 2) ++count;
            if (++frequency[B[i]] == 2) ++count;
            C[i] = count;
        }
        return C;
    }
};