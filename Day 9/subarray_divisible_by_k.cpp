class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> remainders;
        remainders[0]=1;
        int n = nums.size();
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0)rem+=k;
            
            count+=remainders[rem];
            
            remainders[rem]++;
            
        }
        return count;
    }
};