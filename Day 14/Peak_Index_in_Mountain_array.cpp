class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // starting with 1 because we need to compare a previous value
        // end till size()-2 because we need to compare with next value
        int start=1,end=arr.size()-2;
        int ans=1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                ans=mid;
                break;
            }else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};