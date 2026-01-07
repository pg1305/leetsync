class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        vector<long long> levelSums;

        while (!q.empty()) {
            int sz = q.size();
            long long levSum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                levSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levelSums.push_back(levSum);
        }

        if (k > levelSums.size()) return -1;

        sort(levelSums.begin(), levelSums.end());

        return levelSums[levelSums.size() - k];
    }
};
