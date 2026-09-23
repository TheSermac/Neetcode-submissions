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
    vector<int> orderedTree;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return 0;
        }
        mapNodes(root);
        return orderedTree[k-1];
    }

    void mapNodes(TreeNode* root){
        if(root->left != NULL){
            mapNodes(root->left);
        }
        orderedTree.push_back(root->val);
        if(root->right != NULL){
            mapNodes(root->right);
        }
    }
};
