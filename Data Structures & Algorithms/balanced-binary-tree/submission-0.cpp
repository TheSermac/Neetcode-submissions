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
    bool isBalanced(TreeNode* root) {
        int balance = 0;
        if(root == NULL){
            return true;
        }
        else{
            return checkBalance(root, balance);
        }
    }

    bool checkBalance(TreeNode* root, int& depth){
        int depthLeft = 0; int depthRight = 0;
        bool balanceLeft = true; bool balanceRight = true;

        if(root->left != NULL){
            balanceLeft = checkBalance(root->left, depthLeft);
        }
        if(root->right != NULL){
            balanceRight = checkBalance(root->right, depthRight);
        }

        if(balanceLeft && balanceRight && (std::abs(depthLeft - depthRight) <= 1)){
            depth = std::max(depthLeft, depthRight);
            depth++;
            return true;
        }
        
        return false;
    }
};
