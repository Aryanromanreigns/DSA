class Solution {
  public:
    vector <int> bottomView(TreeNode *root){
    	vector<int>ans;
        if(root == NULL)return ans;

        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;

        q.push({root,0});


        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int vertical = it.second;


            mpp[vertical] = node->data;

            if(node->left != NULL){
                q.push({node->left,vertical-1});
            }
            if(node->right != NULL){
                q.push({node->right,vertical+1});
            }



        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;




    }
};