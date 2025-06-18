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
    int findmaxdist(TreeNode* root, TreeNode* target, map<TreeNode* , TreeNode*> &mpp){
        map<TreeNode*, bool> vis;
        queue<TreeNode*> qt;
        qt.push(target);
        vis[target]=1;
        int maxi = 0 ;
        while(!qt.empty()){
            int fl = 0 ;
            int size = qt.size();
            for(int i = 0 ; i< size; i++){
                TreeNode* front = qt.front();
                qt.pop();
                if(front->left && !vis[front->left]){
                    fl = 1;
                    qt.push(front->left);
                    vis[front->left] = 1;
                }
                if(front->right && !vis[front->right]){
                    fl = 1;
                    qt.push(front->right);
                    vis[front->right] = 1;
                }
                if(mpp[front] && !vis[mpp[front]]){
                    fl = 1;
                    qt.push(mpp[front]);
                    vis[mpp[front]] = 1;
                }
            }
            if(fl==1)
            maxi++;

        }
        return maxi;
    }
    TreeNode* parentmap(TreeNode* root, int start, map<TreeNode*, TreeNode*> &mpp){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* front = q.front();
            if(front->val==start){
                res = front ;
            }
            q.pop();
            if(front->left){
                mpp[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                mpp[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = parentmap(root, start, mpp);
        int maxi = findmaxdist( root, target, mpp);
        return maxi;
    }
};