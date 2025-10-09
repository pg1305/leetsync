class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, great, equal;
        for(int num:nums){
            if(num < pivot) less.push_back(num);
            else if(num == pivot) equal.push_back(num);
            else great.push_back(num);
        }
        vector<int> res;
        res.reserve(nums.size());
        res.insert(res.end(), less.begin(), less.end());
        res.insert(res.end(), equal.begin(), equal.end());
        res.insert(res.end(), great.begin(), great.end());
        return res;
    }
};