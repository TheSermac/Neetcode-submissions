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
public:
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, -101);
    }

    int countGoodNodes(TreeNode* node, int maxUp){
        if(node == NULL){
            return 0;
        }
        int ret = node->val >= maxUp ? 1 : 0;
        int max = node->val >= maxUp ? node->val : maxUp;
        ret += countGoodNodes(node->left, max);
        ret += countGoodNodes(node->right, max);
        return ret;
    }
};
