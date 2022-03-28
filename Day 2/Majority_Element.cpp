class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Voting Algorithm
        int majorEle=nums[0],count=0;
        int n = nums.size();
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==majorEle) count++;
            else count--;
            
            if(count==0){
                majorEle=nums[i+1];
            }
        }
        return majorEle;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sorting
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};