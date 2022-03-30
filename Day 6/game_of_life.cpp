class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int x[8]={1,0,-1,0,1,-1,-1,1};
        int y[8]={0,1,0,-1,1,-1,1,-1};
        int n = board.size(),m=board[0].size();
        // 2 - dead made alive
        // 3 - alive made dead
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=0;k<8;k++){
                    if(x[k]+i>=0 && x[k]+i<n && y[k]+j>=0 && y[k]+j<m){
                        if(board[x[k]+i][y[k]+j]==1 || board[x[k]+i][y[k]+j]==3)
                            count++;
                    }
                }
                if(board[i][j]==1){
                    if(count<2 || count>3)
                        board[i][j]=3;
                }else{
                    if(count==3)
                        board[i][j]=2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};