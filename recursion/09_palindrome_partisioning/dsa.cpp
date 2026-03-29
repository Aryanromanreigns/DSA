class Solution {
public:
    bool ispail(string s,int st,int end){
        while(st <= end){
            if(s[st++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void check(string s,vector<vector<string>>&ans,vector<string>&temp
    ,int ind){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = ind ; i < s.size();i++){
            if(ispail(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                check(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        check(s,ans,temp,0);
        return ans;
        
        
    }
};