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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        int depth = 0; 
        if(root == NULL){
            return order;
        }
        computeDepth(root, depth);
        order.resize(depth);
        computeOrder(root, depth, 0, order);
        std::reverse(order.begin(), order.end());
        return order;
    }
    
    void computeDepth(TreeNode* root, int& depth){
        int lDepth = 0; int rDepth = 0;
        if(root->left != NULL){
            computeDepth(root->left, lDepth);
        }
        if(root->right != NULL){
            computeDepth(root->right, rDepth);
        }
        depth = std::max(lDepth,rDepth);
        depth++;
    }

    void computeOrder(TreeNode* root, int depth, int level, vector<vector<int>>& order){
        if(root->left != NULL){
           computeOrder(root->left, depth, level+1, order);
        }
        if(root->right != NULL){
            computeOrder(root->right, depth, level+1, order);
        }

        order[depth - level - 1].push_back(root->val);
    }
};
