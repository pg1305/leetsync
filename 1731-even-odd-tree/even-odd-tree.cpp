class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if ((node->val % 2) == (level % 2)) return false;
                if (level % 2 == 0) {
                    if (node->val <= prev) return false;
                } else {
                    if (node->val >= prev) return false;
                }
                prev = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};
