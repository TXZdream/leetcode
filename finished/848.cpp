#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sum = 0;
        for (int i = shifts.size() - 1; i >= 0; i--) {
            sum += shifts[i] % 26;
            S[i] = (S[i] - 'a' + sum) % ('z' - 'a' + 1) + 'a';
        }
        return S;
    }
};