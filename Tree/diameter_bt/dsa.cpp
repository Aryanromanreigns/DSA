class Solution {
public:
    int diameter(TreeNode* root , int &dia){
        if(root == NULL) return 0;
        
        int lh = diameter(root->left,dia);
        int rh = diameter(root->right,dia);
        dia = max(dia , lh+rh);
        return 1 + max(lh , rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameter(root , dia);
        return dia;
        
    }
};