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
    vector<int> sol;
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root != NULL){
            sideView(root, 0);
        }
        
        return sol;
    }

    void sideView(TreeNode* root, int depth){
        if(sol.size() == depth){
            sol.push_back(root->val);
        }

        if(root->right != NULL){
            sideView(root->right, depth+1);
        }
        if(root->left != NULL){
            sideView(root->left, depth+1);
        }
    }
    
};
