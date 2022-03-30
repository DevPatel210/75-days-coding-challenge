class Solution {
public:
    void combinationSum(vector<int>& candidates,vector<int> curr, int target,int i, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        
        for(;i<candidates.size();i++){
            if(candidates[i]<=target){
                curr.push_back(candidates[i]);
                combinationSum(candidates,curr,target-candidates[i],i,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        combinationSum(candidates,curr,target,0,ans);
        return ans;
    }
};