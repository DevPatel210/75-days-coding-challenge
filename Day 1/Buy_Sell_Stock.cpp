class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int min=INT_MAX,diff=0,n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i]<min)
                min = arr[i];
            else
                diff = max(diff,arr[i]-min);
        }
        return diff;
    }
};