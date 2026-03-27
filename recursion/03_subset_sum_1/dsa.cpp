class Solution {
  public:
    void function(vector<int>& nums, vector<int>& ans , int ind , int sum){
        int n = nums.size();
        if(ind == n){
            ans.push_back(sum);
            return;
        }

        function(nums,ans,ind+1,sum+nums[ind]);
        function(nums,ans,ind+1,sum);
    }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int>ans;
        function(nums,ans,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};