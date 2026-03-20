class Solution{
    public:
    vector<int> topView(TreeNode *root){
        queue<pair<TreeNode* , int>>q;//node,vertical
        map<int,int>mpp;//vertical,data

        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int vertical = it.second;

            if(mpp.find(vertical) == mpp.end()){
                mpp[vertical]=node->data;
            }

            if(node->left != NULL){
                q.push({node->left,vertical-1});
            }
            if(node->right != NULL){
                q.push({node->right,vertical+1});
            }




        }

        vector<int>ans;

        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;

    }
};