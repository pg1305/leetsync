class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> same(2,0) , diff(2,0);
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int currRem = nums[i]%2;
            same[currRem] +=1;
            diff[currRem] = max(diff[currRem],1 + diff[1^currRem]);
        }
        return max({same[0], same[1], diff[0], diff[1]});
    }
};