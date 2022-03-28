class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int start=0,end=n-1;
        
        for(int j=n-1;j>=0;j--){
            if(abs(nums[start]) > abs(nums[end])){
                ans[j] = (nums[start]*nums[start]);
                start++;
            }else{
                ans[j] = (nums[end]*nums[end]);
                end--;
            }
        }
        return ans;
    }
};