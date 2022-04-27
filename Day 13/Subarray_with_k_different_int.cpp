class Solution {
public:
    
    // it is easy to find subarray with atMost k unique elements. So we can use that logic here.
    // To get exactly k unique elements we need to remove atmost k-1 unique elements from atmost k
    // unique elements i.e. atMost(k)-atMost(k-1)
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
    int atMost(vector<int> &nums,int k){
        int start=0,end=0,n=nums.size();
        int count=0;
        map<int,int> freq;
        
        while(end<n){
            freq[nums[end]]++;
            while(freq.size()>k){
                if(freq[nums[start]]==1){
                    freq.erase(nums[start]);
                }else{
                    freq[nums[start]]--;
                }
                start++;
            }
            
            count+=end-start+1;
            end++;
        }
        return count;
    }
};