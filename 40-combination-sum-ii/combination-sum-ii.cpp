class Solution {
    void combination(vector<int> &candidates, int target, int idx, vector<int> &comb, vector<vector<int>> &res){
        if(target < 0){
            return;
        }else if(target == 0) res.push_back(comb);
        else{
            for(int i = idx; i < candidates.size() && target >= candidates[i];i++){
                if(i > idx && candidates[i] == candidates[i - 1])continue;
                comb.push_back(candidates[i]);
                combination(candidates, target - candidates[i], i + 1, comb, res);
                comb.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        combination(candidates, target, 0, comb, res);
        return res;
    }
    };