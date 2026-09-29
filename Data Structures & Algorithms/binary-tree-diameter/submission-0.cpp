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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ret = 0; int bs = 0;
        computeDiameter(root, ret, bs);
        return ret;
    }

    void computeDiameter(TreeNode* root, int& diameter, int& best_side){
        int left = 0; int right = 0; int ret = 0;
        if(root->left != NULL){
            computeDiameter(root->left, diameter, left);
            left++;
        }
        if(root->right != NULL){
            computeDiameter(root->right, diameter, right);
            right++;
        }
        diameter = std::max(diameter, left + right);
        best_side = std::max(left, right);
    }
};
