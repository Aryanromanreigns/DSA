class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[low]<=nums[mid]){
                if(ans>nums[low]){
                    ans = nums[low];
                }
                low = mid + 1;
            }
            else{
                if(ans > nums[mid]){
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }
        return ans;
        
    }
};