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
    int maxelement(TreeNode* root){
        TreeNode* curr = root;
        while(curr->right){
            curr=curr->right;
        }
        return curr->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
        return NULL;
        if(root->val==key){
            if(!root->left && !root->right){
                delete root;
                return NULL;

            }
            else if(root->left && !root->right){
                TreeNode* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else if(!root->left && root->right){
                TreeNode* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else{
                int temp = maxelement(root->left);
                root->val = temp;
                root->left = deleteNode(root->left, temp);
                return root;
            }
        
        }
        if(key<root->val){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};