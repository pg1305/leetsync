class Solution {
public:
int step(const vector<vector<int>>& fruits, int startPos, int left, int right) {
    if (fruits[right][0] <= startPos) {
        return startPos - fruits[left][0];
    } else if (fruits[left][0] >= startPos) {
        return fruits[right][0] - startPos;
    } else {
        return min(abs(startPos - fruits[right][0]),
                   abs(startPos - fruits[left][0])) +
               fruits[right][0] - fruits[left][0];
    }
}

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.size();
        int sum = 0;
        int ans = 0;
        while (right < n) {
            sum += fruits[right][1];
            while (left <= right && step(fruits,startPos,left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;
        
    }
};