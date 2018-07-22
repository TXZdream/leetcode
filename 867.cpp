#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > transpose(vector<vector<int> >& A) {
        int sizeRow = A.size();
        int sizeCol = A[0].size();
        vector<vector<int> > ret(sizeCol);
        for (int i = 0; i < sizeCol; i++) {
            ret[i].resize(sizeRow);
            for (int j = 0; j < sizeRow; j++) {
                ret[i][j] = A[j][i];
            }
        }
        return ret;
    }
};