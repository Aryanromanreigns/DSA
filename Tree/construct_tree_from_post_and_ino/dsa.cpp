class Solution {
public:
    TreeNode* buildtree(vector<int>& inorder , int inst , int inend , vector<int>& postorder,
    int post , int poend , map<int , int>&mpp){
        if(inst > inend  || post > poend){
            return NULL;
        }

        TreeNode* node = new TreeNode(postorder[poend]);
        int innode = mpp[node->val];
        int numsleft = innode - inst;
        node->left = buildtree(inorder,inst,innode-1,postorder,post,post+numsleft-1,mpp);
        node->right = buildtree(inorder,innode+1,inend , postorder,post+numsleft,poend-1,mpp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }

        map<int,int>mpp;

        for(int i = 0 ; i < inorder.size() ; i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildtree(inorder, 0, inorder.size()-1, postorder ,
        0 , postorder.size()-1,mpp);


        return root;
        
    }
};