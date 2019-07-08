#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int y = matrix[0].size() - 1, x = 0;
        while (y >= 0 && x < matrix.size()) {
            if (matrix[x][y] == target) {
                return true;
            }
            if ( matrix[x][y] < target) {
                x++;
            } else {
                y--;
            }
        }
        return false;
    }
};