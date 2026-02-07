class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        int start = 0;
        int ansStart = 0, ansEnd = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sum == 0) start = i;

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        // Printing the subarray
        cout << "Maximum Subarray: ";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;

        return maxi;
    }
};
