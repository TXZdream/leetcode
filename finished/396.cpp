#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        long long sum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
        }
        long long max = 0;
        for (int i = 0; i < A.size(); i++) {
            max += A[i] * i;
        }
        long long last = max;
        cout << last << " ";
        for (int i = 1; i < A.size(); i++) {
            long long tmp = last + sum - A.size() * A[A.size() - i];
            if (tmp > max) {
                max = tmp;
            }
            last = tmp;
            cout << last << " ";
        }
        return int(max);
    }
};