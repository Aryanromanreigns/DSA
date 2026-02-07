class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Case 1: subarray from 0 to i
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Case 2: subarray ending at i
            if (mp.find(sum - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum - k]);
            }

            // Store first occurrence only
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
