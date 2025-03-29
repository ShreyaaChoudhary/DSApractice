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
    int finddepth(TreeNode* root){
        if(root==NULL)return 0;
        return max(finddepth(root->left),finddepth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool flag = abs(finddepth(root->left)-finddepth(root->right))>1?false:true;
        return flag && isBalanced(root->left) && isBalanced(root->right);
    }
};