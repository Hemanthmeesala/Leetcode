class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    (board[nrow][ncol] == 1 || board[nrow][ncol] == 2)){
                        cnt++;
                    }
                }
                if(board[i][j] == 1 && (cnt < 2 || cnt > 3)){
                    board[i][j] = 2;
                }
                else if(board[i][j] == 0 && cnt == 3){
                    board[i][j] = 3;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 2) board[i][j] = 0;
                if(board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};