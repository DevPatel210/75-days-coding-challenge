class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0;i<n-3;i++){
            
            for(int j=i+1;j<n-2;j++){
                int sum=target-nums[i]-nums[j];
                int start=j+1,end=n-1;
                while(start<end){
                    if(sum==(nums[start]+nums[end])){
                        s.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if(sum>(nums[start]+nums[end])) start++;
                    else end--;
                }
            }
        }
        
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};