class Solution {
public:
    bool canAchieve(long long mid, vector<int>& stations, int r, long long k) {
    int n = stations.size();
    vector<long long> power(n), diff(n + 1, 0);

    // Calculate initial power using sliding window
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        curr += stations[i];
        if (i - r - 1 >= 0) curr -= stations[i - r - 1];
        power[i] = curr;
        if (i + r + 1 < n) curr += (stations[i + r + 1]);
    }

    // Reset and recompute correctly
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stations[i];
    for (int i = 0; i < n; i++) {
        int left = max(0, i - r), right = min(n - 1, i + r);
        power[i] = prefix[right + 1] - prefix[left];
    }

    long long added = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) added += diff[i];
        if (power[i] + added < mid) {
            long long need = mid - (power[i] + added);
            if (need > k) return false;
            k -= need;
            added += need;
            int end = min(n, i + 2 * r + 1);
            if (end < n) diff[end] -= need;
        }
    }
    return true;
}

long long maxPower(vector<int>& stations, int r, int k) {
    long long low = 0, high = 1e18, ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canAchieve(mid, stations, r, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
};