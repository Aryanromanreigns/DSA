class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        int maxlen = 1;
        for(int i  = 0;i<n;i++){
            int el = arr[i];
            int cnt = 1;
            for(int j = 0;j<n;j++){
                if(arr[j] == el+1){
                    el = el + 1;
                    cnt++;
                    j=-1;
                }
            }
            maxlen = max(maxlen,cnt);
        }
        return maxlen;
        
    }
};




class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int lastel = arr[0];
        int cnt = 1;
        int maxcnt = 1;

        for(int i = 1;i <n;i++){
            if(arr[i]==arr[i-1])continue;
            if(arr[i] != lastel+1){
                lastel = arr[i];
                cnt = 1;
            }
            else{
                cnt++;
                lastel = arr[i];
            }
            maxcnt = max(maxcnt,cnt);
        }    
        return maxcnt;
    }
};



class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if(n==0)return 0;
        unordered_set<int>st;
        int longest = 1;
        for(int i = 0;i<n;i++){
            st.insert(arr[i]);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int el = it;
                while(st.find(el+1) != st.end()){
                    el = el + 1;
                    cnt++;

                }
                longest = max(longest,cnt);
            }
        }
        return longest;

      
    }
};