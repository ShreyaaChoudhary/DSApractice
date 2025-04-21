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
    int sumNumbers(TreeNode* root) {
        int ans =0;
        int res=0;
        sumpath(root,res,ans);
        return ans;
    }
    void sumpath(TreeNode* root,int &res, int &ans){
        if(root==NULL)
        return ;
        int temp = res;
            res = res*10+root->val;

        if( !root->left && !root->right){
            //leaf node
            ans+=res;
            res = temp;
            return;
        }
        sumpath(root->left,res, ans);
        sumpath(root->right,res,ans);
        res = temp;
    }
};