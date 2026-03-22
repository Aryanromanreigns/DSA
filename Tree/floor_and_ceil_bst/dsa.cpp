
class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			int ceil = -1;
            int floor = -1;

            while(root){
                if(root->data == key){
                    ceil = root->data;
                    floor = root->data;
                    return {ceil,floor};
                }
                else if(key > root->data){
                    floor = root->data;
                    root = root->right;
                }
                else{
                    ceil = root->data;
                    root = root->left;
                }
            }
            return {ceil ,floor};
		}
};