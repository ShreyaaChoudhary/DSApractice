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
    int findheight(TreeNode* root){
        if(root==NULL)
        return 0;
        return 1+ max(findheight(root->left), findheight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
        if(abs(findheight(root->left)-findheight(root->right))>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);

    }
};