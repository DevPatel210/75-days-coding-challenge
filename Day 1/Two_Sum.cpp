class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])!=m.end()){
                if(target-nums[i]==nums[i]){
                    if(m[nums[i]].size()>=2){
                        return {m[nums[i]][0],m[nums[i]][1]};
                    }
                }else{
                    return {m[nums[i]][0],m[target-nums[i]][0]};
                }
            }
        }
        return {0};
    }
};