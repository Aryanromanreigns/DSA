class Solution {
public:
    int lowerBound(vector<int> &nums, int &ans , int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid]>=x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }


        }
        return ans;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();
        lowerBound(nums,ans,target);
        return ans;
        
    }
};