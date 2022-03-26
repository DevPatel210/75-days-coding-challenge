bool compare(vector<int> a,vector<int> b){
    return (a[0]<b[0]);
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end(),compare);
        
        vector<int> temp = intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            if(temp[1] >= intervals[i][0]){
                temp[1] = max(temp[1],intervals[i][1]);
            }else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};