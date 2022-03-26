class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
       
        if(n<3) return {};
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> triplets;
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int start=i+1,end=n-1;
            while(start<end){
                int sum = nums[i]+nums[start]+nums[end];
                if(sum==0){
                    triplets.push_back({nums[i],nums[start],nums[end]});
                    while (start+1<end && nums[start]==nums[start+1]) start++;
                    while (end-1>start && nums[end]==nums[end-1]) end--;
                    start++;
                    end--;
                }else if(sum>0)
                    end--;
                else
                    start++;
            }
        }
        
        return triplets;
        
    }
};