class Solution {
    int cross(const vector<int> &A, const vector<int> &B, const vector<int> &C){
        return (B[0] - A[0])*(C[1] - B[1]) - (B[1] - A[1]) * (C[0] - B[0]);
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() < 3) return trees;
        sort(trees.begin(), trees.end());
        vector<vector<int>> lower, upper;
        for(auto &tree: trees){
            while(lower.size() >= 2 && cross(lower[lower.size() - 2], lower.back(), tree) < 0){
                lower.pop_back();
            }
            lower.push_back(tree);
        }
        for (int i = trees.size() - 1; i >= 0; --i) {
            auto& tree = trees[i];
            while (upper.size() >= 2 && cross(upper[upper.size()-2], upper.back(), tree) < 0)
                upper.pop_back();
            upper.push_back(tree);
        }
        lower.pop_back();
        upper.pop_back();
        set<vector<int>> res (lower.begin(), lower.end());
        res.insert(upper.begin(), upper.end());
        return vector<vector<int>>(res.begin(), res.end());
    }
};