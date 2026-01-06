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
#include<queue>
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        //BFS(QUEUE)
        int maxS = INT_MIN;
        int res = 0, lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            lvl++;
            int levS = 0;
            for(int i = q.size(); i > 0; i--){
                TreeNode* node = q.front();
                q.pop();
                levS += node -> val;
                if(node -> left != NULL){
                    q.push(node -> left);
                }
                if(node -> right != NULL){
                    q.push(node -> right);
                }
            }
            if(maxS < levS){
                maxS = levS;
                res = lvl;
            }
        }
        return res;
    }
};