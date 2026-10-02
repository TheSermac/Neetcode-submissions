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
    TreeNode* sol;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool foundp = false; bool foundq = false;
        lca(root, p, q, foundp, foundq);
        return sol;
    }

    void lca(TreeNode* root, TreeNode* p, TreeNode* q, bool& foundp, bool& foundq){
        if(root == NULL){
            return;
        }

        bool leftP = false; bool leftQ = false;
        bool rightP = false; bool rightQ = false;
        bool amIP = root->val == p->val;
        bool amIQ = root->val == q->val; 
        lca(root->left, p, q, leftP, leftQ);
        lca(root->right, p, q, rightP, rightQ);

        if((leftP || rightP || amIP) && (leftQ || rightQ || amIQ)){
            sol = root;
            foundp = false; foundq = false;
        }
        else{
            foundp = leftP || rightP || amIP;
            foundq = leftQ || rightQ || amIQ;
        }

    }
};
