class Solution {
public:
    int largestElement(vector<int>& nums) {
        if (nums.empty()) return -1; // or throw exception

        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
};
