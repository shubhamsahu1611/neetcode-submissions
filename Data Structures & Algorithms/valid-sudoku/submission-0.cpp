class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            map<char, int> cnt;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    cnt[(board[i][j])]++;
                    if (cnt[(board[i][j])] > 1) return false;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            map<char, int> cnt;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    cnt[(board[j][i])]++;
                    if (cnt[(board[j][i])] > 1) return false;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            map<char, int> cnt;
            for (int j = 0; j < 9; j++) {
                int x=(i/3)*3 + (j%3);
                int y=(i%3)*3 + (j/3);
                if (board[x][y] != '.') {
                    cnt[(board[x][y])]++;
                    if (cnt[(board[x][y])] > 1) return false;
                }
            }
        }
        return true;
    }
};
