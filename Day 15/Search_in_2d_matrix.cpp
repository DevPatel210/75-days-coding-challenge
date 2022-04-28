class Solution {
public:
    bool binarySearch(vector<int> arr,int target){
        int n = arr.size();
        int start=0,end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target)
                return true;
            else if(arr[mid] > target)
                end=mid-1;
            else
                start=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,r=matrix.size(),c=matrix[0].size();
        
        int start=0,end=r-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(matrix[mid][0]==target || matrix[mid][c-1]==target)
                return true;
            
            if(matrix[mid][0]<target && matrix[mid][c-1]>target)
                return binarySearch(matrix[mid],target);
            
            if(target<matrix[mid][0])
                end=mid-1;
            if(target>matrix[mid][c-1])
                start=mid+1;
        }
        return false;
    }
};