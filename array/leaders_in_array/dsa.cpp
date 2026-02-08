class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        if(n==0)return ans;
        ans.push_back(nums[n-1]);
        int maxi = nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i] > maxi){
                maxi = nums[i];
                ans.push_back(nums[i]);

            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
      
    }
};