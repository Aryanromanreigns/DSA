// nums[i] >= target
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int ans = n;
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
};