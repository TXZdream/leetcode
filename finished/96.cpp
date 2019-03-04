#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> record(n + 1);
        record[0] = 1; record[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < i/2; j++) {
                sum += record[j] * record[i-1-j] * 2;
            }
            if (i % 2 != 0) {
                sum += record[i/2] * record[i/2];
            }
            record[i] = sum;
        }
        return record[n];
    }
};