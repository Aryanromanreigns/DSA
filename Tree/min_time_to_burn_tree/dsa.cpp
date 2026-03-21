class Solution {
public:

    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
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

    int minTime(TreeNode* root, TreeNode* target) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int time = 0;

        while(!q.empty()){
            int size = q.size();
            bool burnedSomething = false;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                // left
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                    burnedSomething = true;
                }

                // right
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                    burnedSomething = true;
                }

                // parent
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                    burnedSomething = true;
                }
            }

            if(burnedSomething) time++;
        }

        return time;
    }
};