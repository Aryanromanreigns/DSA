class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        int ind = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[low] <= nums[high]){
                if(nums[low]<ans){
                    ind = low;
                    ans=nums[low];
                }
                break;
            }
            if(nums[low]<=nums[mid]){
                if(ans>nums[low]){
                    ind = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }
            else{
                if(ans > nums[mid]){
                    ind = mid;
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }
        return ind;
        
    }
};
        