class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            map<char, int> cnt1;
            map<char, int> cnt2;
            map<char, int> cnt3;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    cnt1[(board[i][j])]++;
                    if (cnt1[(board[i][j])] > 1) return false;
                }
                if (board[j][i] != '.') {
                    cnt2[(board[j][i])]++;
                    if (cnt2[(board[j][i])] > 1) return false;
                }
                int x=(i/3)*3 + (j%3);
                int y=(i%3)*3 + (j/3);
                if (board[x][y] != '.') {
                    cnt3[(board[x][y])]++;
                    if (cnt3[(board[x][y])] > 1) return false;
                }
            }
        }
        return true;
    }
};
