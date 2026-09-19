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
    vector<vector<int>> order;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Case it is null
        if(root == NULL){
            return order;
        }
        //Otherwise compute order
        computeOrder(root, 0);
        return order;
    }

    void computeOrder(TreeNode* root, int depth){
        if (order.size() == depth) {
            order.push_back(vector<int>());
        }

        order[depth].push_back(root->val);

        if(root->left != NULL){
           computeOrder(root->left, depth + 1);
        }
        if(root->right != NULL){
            computeOrder(root->right, depth + 1);
        }
    }
};
