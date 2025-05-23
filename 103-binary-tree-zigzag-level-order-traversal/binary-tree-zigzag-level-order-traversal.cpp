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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> row(n);
            for(int i = 0 ; i< n ; i++){
                TreeNode* curr  = q.front();
                q.pop();
                int index = flag?i:n-i-1;
                row[index] = curr->val; 
                if(curr->left)
                q.push(curr->left);
                if(curr->right){
                    q.push(curr->right);
                }
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;

    }
};