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
private:
    TreeNode* originalSubRoot;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        originalSubRoot = subRoot;
        return checkSubtree(root, subRoot);
    }

    bool checkSubtree(TreeNode* root, TreeNode* subRoot){
        bool ret = false;
        // Get out condition
        if(root == NULL && subRoot == NULL){
            return true;
        }
        else if(root == NULL || subRoot == NULL){
            return false;
        }

        if(root->val == subRoot->val){
            ret = checkSubtree(root->left, subRoot->left) && checkSubtree(root->right, subRoot->right);
        }
        else{
            subRoot = originalSubRoot;
        }

        return ret || checkSubtree(root->left, subRoot) || checkSubtree(root->right, subRoot);
    }
};
