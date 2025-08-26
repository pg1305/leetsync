class Solution {
    void combination(vector<int> &candidates, int target, int idx, vector<int> &comb, int tot, vector<vector<int>> &res){
        if(tot == target){
            res.push_back(comb);
            return;
        }
        if(tot > target || idx >= candidates.size()) return;
        comb.push_back(candidates[idx]);
        combination(candidates, target, idx, comb, tot + candidates[idx], res);
        comb.pop_back();
        combination(candidates, target, idx + 1, comb, tot, res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = candidates.size();
        vector<int> comb;
        combination(candidates, target, 0, comb, 0, res);
        return res;
    }
};