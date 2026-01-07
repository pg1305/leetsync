class Solution {
    using LL = long long;
    LL MOD = 1e9 + 7;
    LL dfs(TreeNode* node) {
        if (!node) return 0;
        node->val += dfs(node->left) + dfs(node->right);
        return node->val;
    }
public:
    int maxProduct(TreeNode* root) {
        LL res = 0;
        LL total = dfs(root);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) continue;
            LL curr = (total - node->val) * node->val;
            res = max(res, curr);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return res % MOD;
    }
};