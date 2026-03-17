class Solution{
	public:
		vector<vector<int> > treeTraversal(TreeNode* root){
			stack<pair<TreeNode*, int>>st;
            vector<int>pre , ino , pos ;

            if(root == NULL)return {};
            st.push({root , 1});

            while(!st.empty()){
                auto it = st.top();
                st.pop();
                if(it.second == 1){
                    pre.push_back(it.first->val);
                    it.second++;
                    st.push(it);

                    if(it.first->left != NULL){
                        st.push({it.first->left,1})
                    }

                }
                else if(it.second == 2){
                    ino.push_back(it.first->val);
                    it.second++;
                    st.push(it);

                    if(it.first->right != NULL){
                        st.push({it.right->right,1});
                    }

                }
                else{
                    pos.push_back(it.first->val);

                }



            }

            return {pre , ino , pos};
            
            
		}
};