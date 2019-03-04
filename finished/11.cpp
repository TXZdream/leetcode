#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = -1;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                if ((j - i) * (min(height[i], height[j])) > max) {
                    max = (j - i) * min(height[i], height[j]);
                }
            }
        }
        return max;
    }
};