class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            if(arr[i] == 1){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
        
    }
};