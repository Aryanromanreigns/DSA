class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>numfreq;
        unordered_map<int , int>freqcnt;

        for(int i = 0 ; i < n ; i++){
            numfreq[nums[i]]++;
           
        }
        for(auto it : numfreq){
            freqcnt[it.second]++;
        }

        for(int i = 0 ; i < n ; i++){
            int val = numfreq[nums[i]];
            if(freqcnt[val] == 1){
                return nums[i];
            }
        }

       
      
        return -1;
        
    }
};