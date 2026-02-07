class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int>pos;
        vector<int>neg;
        for(int i = 0;i<n;i++){
            if(arr[i] > 0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        int p = pos.size();
        int m = neg.size();

        if(p < n){
            for(int i = 0;i<p;i++){
                arr[i*2] = pos[i];
                arr[i*2 + 1] = neg[i];
            }
            int ind = p*2;
            for(int i = p;i<m;i++){
                arr[ind] = neg[i];
                ind++;
            }

        }
        else{
            for(int i = 0;i<m;i++){
                arr[i*2] = pos[i];
                arr[i*2 + 1] = neg[i];
            }
            int ind = m*2;
            for(int i = m;i<p;i++){
                arr[ind] = neg[i];
                ind++;
            }

        }
        return arr;
        
    }
};