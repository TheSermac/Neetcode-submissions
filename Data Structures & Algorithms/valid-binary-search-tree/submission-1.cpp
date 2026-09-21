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
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return checkValidBST(root, -1000000001, 1000000001);
    }

    bool checkValidBST(TreeNode* root, int min, int max){
        bool left = true; bool right = true;

        if(root->val <= min || root->val >= max){
            return false;
        }

        if(root->left != NULL){
            left = checkValidBST(root->left, min, root->val);
        }
        if(root->right != NULL){
            right = checkValidBST(root->right, root->val, max);
        }

        return left && right;
    }
};
