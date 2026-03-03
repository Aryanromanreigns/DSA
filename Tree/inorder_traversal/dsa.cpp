class Solution {
public:
    void inorder(TreeNode* root , vector<int>&ans){
        TreeNode* temp = root;
        if(root == NULL){
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(temp->val);
        inorder(temp->right , ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root , ans);
        return ans;
        
    }
};