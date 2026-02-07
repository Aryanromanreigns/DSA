class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += arr[i];
        }
        int tot = 0;
        tot = (n * (n+1))/2;
        return tot - sum;
        
    }
};