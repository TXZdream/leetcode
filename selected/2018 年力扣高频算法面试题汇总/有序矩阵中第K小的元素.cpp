#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> res;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                res.push(matrix[i][j]);
            }
        }
        int size = matrix.size();
        size *= size;
        for (int i = 0; i < size - k; i++) {
            res.pop();
        }
        return res.top();
    }
};