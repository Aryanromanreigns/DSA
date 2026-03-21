class Solution {
public:
    TreeNode* buildtree(vector<int>&preorder , int prest , int preend , vector<int>&
    inorder , int inst , int inend,map<int,int>&mpp){
        if(prest > preend || inst > inend) return NULL;


        TreeNode* node = new TreeNode(preorder[prest]);
        int inmpp = mpp[node->val];

        int numsleft = inmpp - inst;

        node->left = buildtree(preorder,prest+1,prest+numsleft,  inorder, inst, inmpp-1, mpp);
        node->right = buildtree(preorder,prest+numsleft+1,preend , inorder,inmpp+1,inend,mpp);

        return node;

        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildtree(preorder ,0 , preorder.size()-1, inorder,0,
        inorder.size()-1 , mpp);

        return root;
        
    }
};