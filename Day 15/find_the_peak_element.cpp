class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            
            int a,b;
            if(mid==0){
                a=INT_MIN;
            }else{
                a=nums[mid-1];
            }
            
            if(mid==nums.size()-1){
                b=INT_MIN;
            }else{
                b=nums[mid+1];
            }
            
            if(a<nums[mid] && nums[mid]>b){
                // peak
                return mid;
            }else if(a<nums[mid] && nums[mid]<b){
                // ascending
                start=mid+1;
            }else if(a>nums[mid] && nums[mid]>b){
                // descending
                end=mid-1;
            }else{
                // dip
                start=mid+1;
            }
        }
        return 0;
    }
};