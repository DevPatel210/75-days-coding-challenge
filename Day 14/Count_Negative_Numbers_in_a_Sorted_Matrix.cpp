// Binary Search Solution - O(N*LogM)
class Solution1 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            int start=0,end=m-1;
            int ans=-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                
                if(grid[i][mid]<0){
                    ans=mid;
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }
            if(ans!=-1)
                count+=(m-ans);
        }
        return count;
    }
};

// Linear Solution - O(M+N)

class Solution2 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n = grid.size(),m=grid[0].size();
        int r=n-1,c=0;
        
        // We start from bottom left and go till top right as the grid is sorted in decreasing order
        // in both row and column. If we get a negative value means after this element in the current 
        // row every index will be -ve. So we add them in ans and go to upper row. Till we find a -ve
        // value we go towards right i.e. decrease column index.
        while(r>=0 && c<m){
            if(grid[r][c] < 0){
                count+=(m-c);
                r--;
            }else{
                c++;
            }
        }
        return count;
    }
};