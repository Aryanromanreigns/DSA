class Solution {
public:
    void postorder(TreeNode* root , vector<int>&ans){
        TreeNode* temp = root;
        if(temp == NULL){
            return ;
        }
        postorder(temp->left , ans);
        postorder(temp->right , ans);
        ans.push_back(temp->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root, ans);
        return ans;
        
    }
};