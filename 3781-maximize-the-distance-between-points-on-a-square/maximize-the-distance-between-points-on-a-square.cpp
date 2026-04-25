class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> a;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                a.push_back(y);
            } else if (y == side) {
                a.push_back(side + x);
            } else if (x == side) {
                a.push_back(side * 3LL - y);
            } else {
                a.push_back(side * 4LL - x);
            }
        }
        ranges::sort(a);

        auto check = [&](int low) -> bool {
            vector<int> idx(k);
            long long cur = a[0];
            for (int j = 1; j < k; j++) {
                int i = ranges::lower_bound(a, cur + low) - a.begin();
                if (i == a.size()) {
                    return false;
                }
                idx[j] = i;
                cur = a[i];
            }
            if (cur - a[0] <= side * 4LL - low) {
                return true;
            }

            // 第一个指针移动到第二个指针的位置，就不用继续枚举了
            int end0 = idx[1];
            for (idx[0]++; idx[0] < end0; idx[0]++) {
                for (int j = 1; j < k; j++) {
                    while (a[idx[j]] < a[idx[j - 1]] + low) {
                        idx[j]++;
                        if (idx[j] == a.size()) {
                            return false;
                        }
                    }
                }
                if (a[idx[k - 1]] - a[idx[0]] <= side * 4LL - low) {
                    return true;
                }
            }
            return false;
        };

        int left = 1, right = side + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};