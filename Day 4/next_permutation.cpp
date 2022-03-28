class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        
        int i = nums.size()-2;
        while( i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        
        if(i<0){
            reverse(nums.begin(),nums.end());
        }else{
            int greater = nums.size()-1;
            while(nums[greater]<=nums[i])
                greater--;
            swap(nums[i],nums[greater]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};