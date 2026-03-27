class Solution {
public:
    void permutation(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int freq[]){
        int n = nums.size();
        if(temp.size() == n){
            ans.push_back(temp);
            return ;
        }

        for(int i = 0 ; i < n ; i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i] = 1;
                permutation(nums,ans,temp,freq);
                freq[i] = 0;
                temp.pop_back();


            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int freq[nums.size()];
        for(int i = 0 ; i < nums.size();i++){
            freq[i] =0;

        }

        permutation(nums,ans,temp,freq);
        return ans;
        
    }
};












class Solution {
public:
    void permutation(int ind,vector<vector<int>>&ans,vector<int>&nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size() ; i++){
            swap(nums[ind],nums[i]);
            permutation(ind+1,ans,nums);
            swap(nums[ind],nums[i]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation(0,ans,nums);
        return ans;
        
    }
};