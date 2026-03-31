class Solution {
public:
    int lastocc(vector<int>&nums , int &x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high -  low)/2;
            if(nums[mid] == x){
                ans = mid;
                low = mid + 1;
            }
            else if(x > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    int firstocc(vector<int>&nums , int &x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high -  low)/2;
            if(nums[mid] == x){
                ans = mid;
                high = mid - 1;
            }
            else if(x > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    int searchRange(vector<int>& nums, int& target) {
        int first = firstocc(nums,target);
        if(first == -1) return 0;
        int last = lastocc(nums,target);
        return last - first + 1;
        
        
    }

    int countOccurrences(vector<int>& arr, int target) {
        // Your code goes here
        return searchRange(arr,target);
    }
};