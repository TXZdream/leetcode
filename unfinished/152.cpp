#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int currMax = nums[0], currMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int tmp = currMax;
                currMax = currMin;
                currMin = tmp;
            }
            
        }
        return max;
    }
};