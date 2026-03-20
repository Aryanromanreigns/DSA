class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int , int>>>q;//node,vertical,level
        map<int,map<int,multiset<int>>>mpp;//vertical,level,nodesss

        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mpp[x][y].insert(node->val);

            if(node->left != NULL){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right != NULL){
                q.push({node->right,{x+1,y+1}});
            }


        }
        vector<vector<int>>ans;
        for(auto it : mpp){
            vector<int>level;
            for(auto node : it.second){
                level.insert(level.end(),node.second.begin(),node.second.end());
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};