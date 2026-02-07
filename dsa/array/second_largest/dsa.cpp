class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if (nums.size() < 2) return -1;

        int fl = INT_MIN, sl = INT_MIN;
        bool found = false;

        for (int x : nums) {
            if (x > fl) {
                sl = fl;
                fl = x;
                found = true;
            }
            else if (x < fl && x > sl) {
                sl = x;
                found = true;
            }
        }

        return (sl == INT_MIN && !found) ? -1 : sl;
    }
};
