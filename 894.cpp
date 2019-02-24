#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int leftBefore = -1, rightBefore = -1;
        int max = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                continue;
            }
            if (i == 0 || seats[i - 1]) {
                if (i == 0) {
                    leftBefore = -1;
                } else {
                    leftBefore = 1;
                }
                int rightSum = 0;
                for (int j = i + 1; j < seats.size(); j++) {
                    rightSum++;
                    if (seats[j]) {
                        break;
                    }
                }
                rightBefore = rightSum;
            } else {
                leftBefore++;
                rightBefore--;
            }
            if (i == seats.size() - 1) {
                rightBefore = -1;
            }
            int currMax = leftBefore;
            if (rightBefore != -1 && (leftBefore == -1 || rightBefore < currMax)) {
                currMax = rightBefore;
            }
            if (currMax > max) {
                max = currMax;
            }
        }
        return max;
    }
};