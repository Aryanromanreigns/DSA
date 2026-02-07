class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int ,int>mpp;
        for(int i = 0;i<n;i++){
            int a = nums[i];
            int r = target - a;
            if(mpp.find(r)!=mpp.end()){
                return {mpp[r],i};
            }
            mpp[a] = i;
        }
        return {-1,-1};
        
    }
};