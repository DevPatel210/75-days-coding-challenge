class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=-1,b=-1;
        int start=0,end=nums.size()-1;
        
        // first position
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(nums[mid]==target){
                a=mid;
                end=mid-1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        start=0,end=nums.size()-1;
        
        // last position
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(nums[mid]==target){
                b=mid;
                start=mid+1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return {a,b};
    }
};