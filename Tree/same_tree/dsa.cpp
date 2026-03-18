class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }

        int left = isSameTree(p->left,q->left);
        int right = isSameTree(p->right,q->right);


        if(left && right){
            return true;
        }
        else{
            return false;
        }

        
    }
};