// Time Limit exceed
#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int> > matrix) {
        this->matrix.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            this->matrix[i].push_back(matrix[i][0]);
            for (int j = 1; j < matrix[i].size(); j++) {
                this->matrix[i].push_back(this->matrix[i].back() + matrix[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += matrix[i][col2];
            if (col1 != 0) {
                sum -= matrix[i][col1 - 1];
            }
        }
        return sum;
    }
private:
    vector<vector<int> > matrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */