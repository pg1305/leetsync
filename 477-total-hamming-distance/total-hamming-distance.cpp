class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2)
            return 0;
        int res = 0;
        int zeroOne[2];
        while (true) {
            int zc = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for (int i = 0; i < sz; i++) {
                if (nums[i] == 0)
                    zc++;
                zeroOne[nums[i] % 2]++;
                nums[i] >>= 1;
            }
            res += zeroOne[0] * zeroOne[1];
            if (zc == sz)
                return res;
        }
    }
};