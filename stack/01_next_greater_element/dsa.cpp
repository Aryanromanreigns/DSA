class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num, vector<int>& nums) {
        int n = num.size();
        int m = nums.size();

        vector<int>ans;

        for(int i = 0;i < n; i++){
            int val = num[i];
            int ind = -1;
            
            for(int j = 0; j < m;j++){
                if(val == nums[j]){
                    ind = j;
                    break;
                }
            }
            int next = -1;
            for(int k=ind+1;k<m;k++){
                if(val < nums[k]){
                    next = nums[k];
                    break;a
                }
            }
            ans.push_back(next);
        }
        return ans;
        
    }
};