class Solution {
public:
    void subset(vector<int>&nums , vector<vector<int>>& ans , vector<int>& temp , int ind){
        int n = nums.size();


        ans.push_back(temp);

        for(int i = ind ; i < n ; i++){
            if(i != ind && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            subset(nums,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        subset(nums,ans,temp,0);
        return ans;
    }
};