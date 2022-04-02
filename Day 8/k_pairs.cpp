class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        int n = arr.size(), count=0;
        sort(arr.begin(),arr.end());
        
        int i=0,j=1;
        while(i<n && j<n){
            if(arr[j]-arr[i]==k){
                count++;
                while(i<n-1 && arr[i]==arr[i+1])
                    i++;
                i++;
                while(j<n-1 && arr[j]==arr[j+1])
                    j++;
                j++;
                
            }else if(arr[j]-arr[i]>k){
                i++;
            }else{
                j++;
            }
            
            if(i==j) j=i+1;
            // cout<<i<<" "<<j<<"\n";
        }
        return count;
    }
};