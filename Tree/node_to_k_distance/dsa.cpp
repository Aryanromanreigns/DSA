class Solution {
public:
    void markparent(TreeNode* root ,unordered_map<TreeNode* , 
        TreeNode*>&parent_track ,TreeNode* target){
            queue<TreeNode*>q;

            q.push(root);

            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    parent_track[node->left] = node;
                    q.push(node->left); 
                }
                if(node->right){
                    parent_track[node->right] = node;
                    q.push(node->right);
                }
            }



    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parent_track;
        markparent(root,parent_track,target);

        unordered_map<TreeNode* , bool>visited;

        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int dis = 0;

        while(!q.empty()){
            int size = q.size();
            if(dis == k)break;
            dis++;

            for(int i = 0; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();
                //lfor left node
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }


                //for right node
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }


                //for parent node
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }


            }
            
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            ans.push_back(node->val);
        }
        return ans;
        
    }
};