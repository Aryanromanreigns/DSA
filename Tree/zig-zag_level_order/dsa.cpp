class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            
            int size = q.size();
            vector<int>arr(size);

            for(int i = 0 ; i < size ; i++){
                auto it = q.front();
                q.pop();

                int index = flag ? i : size - i - 1;
                arr[index] = it->val;

                if(it->left != NULL){
                    q.push(it->left);
                }
                if(it->right != NULL){
                    q.push(it->right);
                }
                
                

            }
            flag = !flag;
            ans.push_back(arr);
        }
        return ans;


        
    }
};