class Solution {
public:
    void combination(vector<int>&candidates,int target,int ind,vector<vector<int>>&ans,
    vector<int>&temp, int sum){
        int n = candidates.size();
        
        if(ind == n){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }

        if(sum > target) return;
        sum += candidates[ind];
        temp.push_back(candidates[ind]);
        combination(candidates,target,ind,ans,temp,sum);

        temp.pop_back();
        sum -= candidates[ind];
        combination(candidates,target,ind+1,ans,temp,sum);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = 0;
        combination(candidates,target,0,ans,temp,sum);
        return ans;
        
    }
};