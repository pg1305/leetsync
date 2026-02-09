/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    using tree = TreeNode*;
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        tree dummy = new TreeNode(0);
        dummy -> right = root;
        tree curr = dummy;
        while(curr -> right){
            if(curr -> right -> left) rightRotate(curr, curr -> right);
            else curr = curr -> right;
        }
        int count = 0;
        curr = dummy -> right;
        while(curr){
            ++count;
            curr = curr -> right;
        }
        int m = pow(2, floor(log2(count + 1))) - 1;
        makeRotation(dummy, count - m);
        while(m > 1){
            m /= 2;
            makeRotation(dummy, m);
        }
        tree balRoot = dummy -> right;
        delete dummy;
        return balRoot;
    }
    void rightRotate(tree parent, tree node){
        tree temp = node -> left;
        node -> left = temp -> right;
        temp -> right = node;
        parent -> right = temp;
    }
    void leftRotate(tree parent, tree node){
        tree temp = node -> right;
        node -> right = temp -> left;
        temp -> left = node;
        parent -> right = temp;
    }
    void makeRotation(tree dummy, int count){
        tree curr = dummy;
        for(int i = 0; i < count; ++i){
            tree temp = curr -> right;
            leftRotate(curr, temp);
            curr = curr -> right;
        }
    }
};