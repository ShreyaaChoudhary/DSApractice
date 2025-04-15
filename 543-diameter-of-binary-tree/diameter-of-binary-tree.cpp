class Solution {
public:
    int maxi = 0;

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        maxi = max(maxi, lh + rh); // update diameter
        return 1 + max(lh, rh);    // return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};
