class NumMatrix {
   public:
    vector<vector<int>> pre_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> col_pre(m, vector<int>(n, 0));
        pre_sum.assign(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += matrix[j][i];
                col_pre[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += col_pre[j][i];
                pre_sum[i][j] = sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = pre_sum[row2][col2];
        if (row1 > 0 && col1 > 0) ans += pre_sum[row1 - 1][col1 - 1];
        if (row1 > 0) ans -= pre_sum[row1 - 1][col2];
        if (col1 > 0) ans -= pre_sum[row2][col1 - 1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */