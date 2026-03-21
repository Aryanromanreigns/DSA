class Solution {
public:
    void inorder(TreeNode* root , int & cnt){
        if(root == NULL){
            return ;
        }
        cnt++;
        inorder(root->left,cnt);
        inorder(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        inorder(root,cnt);
        return cnt;
        
    }
};