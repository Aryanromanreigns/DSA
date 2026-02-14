class Solution {
public:
    typedef pair<char,int>p;
    struct greaterr{
        bool operator()(p &p1 ,p &p2){
            return p1.second < p2.second; //heap ke top me maxm freq wali entery ho ge
        }
    };
    string frequencySort(string s) {
        priority_queue<p ,vector<p> ,greaterr>pq;
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        for(auto it : mpp){
            pq.push({it.first,it.second});
        }
        string ans = "";

        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();

            ans += string(temp.second , temp.first);

        }

        return ans;

        
        
    }
};