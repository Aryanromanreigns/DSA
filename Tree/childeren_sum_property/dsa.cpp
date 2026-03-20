class Solution {
public:
    void ChildrenSum(TreeNode* root) {
        // up do down
        if(root == NULL){
            return ;
        }
        int sum = 0;
        if(root->left){
            sum += root->left->val;
        }
        if(root->right){
            sum += root->right->val;
        }

        if(sum >= root->val){
            root->val = sum;
        }
        else{
            if(root->left) root->left->val = root->val;
            if(root->right)root->right->val = root->val;
        }

        ChildrenSum(root->left);
        ChildrenSum(root->right);

        //down to up 
        int tot = 0;
        if(root->left){
            tot += root->left->val;
        }

        if(root->right){
            tot += root->right->val;
        }

        if(root->left || root->right){
            root->val = tot;
        }

    }
};