class Solution {
public:
    void preorder(TreeNode* root , vector<int>&ans){
        TreeNode* temp = root;
        if(temp == NULL){
            return ;
        }
        ans.push_back(temp->val);
        preorder(temp->left , ans);
        preorder(temp->right , ans);

    }
    vector<int> preorderTraversal(TreeNode* root) {
       
       
        vector<int>ans;
        preorder(root, ans);

        

        return ans;
        

        
    }
};