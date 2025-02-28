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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;
        TreeNode* empty =0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                if(curr->val==val){
                    return curr;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return empty;
    }
};