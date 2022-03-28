class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0),rightSum(n,0);
        
        for(int i=1;i<n;i++){
            leftSum[i]=leftSum[i-1]+nums[i-1];
            rightSum[n-i-1]=rightSum[n-i]+nums[n-i];
        }
        
        for(int i=0;i<n;i++){
            if(leftSum[i]==rightSum[i])
                return i;
        }
        return -1;
    }
};

class Space_Optimized_Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum=0,leftSum=0;
        
        for(auto x:nums)
            sum+=x;
        
        for(int i=0;i<n;i++){
            if(leftSum==sum-leftSum-nums[i]) return i;
            leftSum+=nums[i];
        }
        
        return -1;
    }
};