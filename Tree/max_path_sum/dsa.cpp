class Solution {
public:
    int path(TreeNode* root , int &ans){
        if(root == NULL)return 0;
        int ls = max(0,path(root->left,ans));
        int rs = max(0,path(root->right,ans));
        ans = max(ans , ls+rs+root->val);
        return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        path(root , ans);
        return ans;
        
    }
};