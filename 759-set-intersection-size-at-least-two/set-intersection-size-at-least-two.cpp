class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        int ans = 0;
        vector<int> pre;

        for (auto &v : intervals) {
            int s = v[0], t = v[1];
            if (pre.empty() || pre[1] < s) {
                ans += 2;
                pre = {t - 1, t};
            }
            else if (pre[0] < s) {
                ans += 1;
                pre = {pre[1], t};
            }
        }

        return ans;
    }
};
