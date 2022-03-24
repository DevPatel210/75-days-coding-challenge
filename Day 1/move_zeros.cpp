class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int p1=0,p2=1;
        for(;p1<n;p1++){
            if(nums[p1]==0)
                break;
        }
        for(p2=p1+1;p2<n;p2++){
            if(nums[p2]!=0)
                break;
        }
        
        while(p1<n && p2<n){
            if(p1>p2) break;
            if(nums[p2]!=0 && nums[p1]==0){
                swap(nums[p1],nums[p2]);
                p1++;
                p2++;
            }else if(nums[p2]==0){
                p2++;
            }else if(nums[p1]!=0){
                p1++;
            }
        }
    }
};