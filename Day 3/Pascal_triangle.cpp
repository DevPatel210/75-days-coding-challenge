class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        for(int i=2;i<=numRows;i++){
            int start=0,end=i-1;
            vector<int> row(i);
            row[start]=row[end]=1;
            for(int j=start+1;j<end;j++){
                row[j]=triangle[i-2][j-1]+triangle[i-2][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};