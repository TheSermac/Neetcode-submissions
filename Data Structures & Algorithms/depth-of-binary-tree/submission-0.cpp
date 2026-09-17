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
    int maxDepth(TreeNode* root) {
        int depthLeft = 0; int depthRight = 0;
        if(root == NULL){
            return 0;
        }
        if(root->left != NULL){
            depthLeft = maxDepth(root->left); 
        }
        if(root->right != NULL){
            depthRight = maxDepth(root->right);
        }
        int depth = max(depthLeft, depthRight);
        depth++;
        return depth;
    }
};
