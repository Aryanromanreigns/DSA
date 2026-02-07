class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                k = i;
                break;
            }
        }
        for(int j = k+1;j<n;j++){
            if(nums[j]!=0){
                swap(nums[k],nums[j]);
                k++;
            }
        }
        
    }
};