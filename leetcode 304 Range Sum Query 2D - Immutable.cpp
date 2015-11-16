// leetcode 304 Range Sum Query 2D - Immutable.cpp

class NumMatrix {
private:
    int row;
    int col;
    int ** sums;

public:
    NumMatrix(vector<vector<int>> &matrix) {

        int i, j;
        row = matrix.size();
        col = row ? matrix[0].size() : 0;
        sums = new int * [row];

        for (i = 0; i < row; i++) sums[i] = new int[col];

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                sums[i][j] = matrix[i][j] + (i ? sums[i - 1][j] : 0) + (j ? sums[i][j - 1] : 0) - (i && j ? sums[i - 1][j - 1] : 0);
            }
        }

    }

    ~NumMatrix() {

        int i;

        for (i = 0; i < row; i++) delete sums[i];

        delete sums;

    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        return sums[row2][col2] - (col1 ? sums[row2][col1 - 1] : 0) - (row1 ? sums[row1 - 1][col2] : 0)
            + (row1 && col1 ? sums[row1 - 1][col1 - 1] : 0);

    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
