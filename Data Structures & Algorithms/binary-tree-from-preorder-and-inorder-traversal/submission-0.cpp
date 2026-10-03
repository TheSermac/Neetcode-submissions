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
    map<int,int> valToPosI;

    TreeNode* constructTree(const vector<int>& preorder, const vector<int>& inorder, int& pos, int start, int end){
        int val = preorder[pos];
        // Añadimos el asterisco (*) para declarar un puntero
        TreeNode* root = new TreeNode(val);

        if(valToPosI[val] > start){
            pos++;
            root->left = constructTree(preorder, inorder, pos, start, valToPosI[val] - 1);
        }
        
        if(valToPosI[val] < end){
            pos++;
            root->right = constructTree(preorder, inorder, pos, valToPosI[val] + 1, end);
        }
        
        return root;
    }

    void buildMap(vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            valToPosI[inorder[i]] = i;
        }
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        buildMap(inorder);
        return constructTree(preorder,inorder,pos,0, inorder.size()-1);
    }
};
