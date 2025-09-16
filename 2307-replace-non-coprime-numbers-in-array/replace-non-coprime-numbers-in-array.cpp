class Solution {
    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                long long a = st.back(); 
                long long b = st[st.size() - 2];
                long long g = __gcd(a, b); 
                if (g == 1) break;
                st.pop_back();
                st.pop_back();
                st.push_back(lcm(a, b));
            }
        }
        vector<int> res(st.begin(), st.end());
        return res;
    }
};
