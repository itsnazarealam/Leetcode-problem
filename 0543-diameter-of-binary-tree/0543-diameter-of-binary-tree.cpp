class Solution {
public:
    int maxi = 0;
    int height(TreeNode* root){
        if(root==NULL)
            return 0;

        int leftSum = height(root->left);
        int rightSum = height(root->right);

        maxi = max(leftSum + rightSum, maxi);

        return max(leftSum, rightSum)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);
        
        return maxi;
    }
};
