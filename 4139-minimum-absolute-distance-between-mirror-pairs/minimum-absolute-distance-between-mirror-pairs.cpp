class Solution {
    int rev(int x){
        int y = 0;
        while(x > 0){
            y = y*10 + x % 10;
            x/=10;
        }
        return y;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int res = n + 1;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            int x = nums[i];
            if(mp.count(x)){
                res = min(res, i - mp[x]);
            }
            mp[rev(x)] = i;
        }
        return res == n + 1? -1: res;
    }
};