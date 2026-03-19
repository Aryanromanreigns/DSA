
class Solution{
public:
    bool isleaf(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void addrightboundary(TreeNode*root , vector<int>&ans){
        TreeNode* cur = root->right;
        vector<int>temp;
        while(cur){
            if(!isleaf(cur)) temp.push_back(cur->data);
            if(cur->right != NULL){
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }

            for(i = temp.size() - 1 ; i >= 0 ; i--){
                ans.push_back(temp[i]);
            }
        }
    }
    void addleftboundary(TreeNode*root ,vector<int>&ans){
        TreeNode* curr = root->left;
        while(curr){
            if(!isleaf(curr))ans.push_back(c->data);
            if(curr->left != NULL){

            curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }
    void addleafnodes(TreeNode* root , vector<int>&ans){
        if(isleaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left) addleafnodes(root->left , ans);
        if(root->right) addleafnodes(root->right , ans);
    }
    vector <int> boundary(TreeNode* root){
        vector<int>ans;
        if(root == NULL)return ans;

        if(!isleaf(root)) ans.push_back(root->data);
        addleftboundary(root,ans);
        addleafnodes(root,ans);
        addrightboundary(root,ans);
        return ans;
    	
    }
};