class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // vector<int> less, great, equal;
        // for(int num:nums){
        //     if(num < pivot) less.push_back(num);
        //     else if(num == pivot) equal.push_back(num);
        //     else great.push_back(num);
        // }
        // vector<int> res;
        // res.reserve(nums.size());
        // res.insert(res.end(), less.begin(), less.end());
        // res.insert(res.end(), equal.begin(), equal.end());
        // res.insert(res.end(), great.begin(), great.end());
        // return res;
        vector<int> res(nums.size());
        int less = 0, equal = 0;
        for(int num:nums){
            if(num < pivot) less++;
            else if(num == pivot) equal++;
        }
        int i1 = 0, i2 = less, i3 = less + equal;
        for(int num:nums){
            if(num < pivot) res[i1++] = num;
            else if(num == pivot) res[i2++] = num;
            else res[i3++] = num;
        }
        return res;
    }
};