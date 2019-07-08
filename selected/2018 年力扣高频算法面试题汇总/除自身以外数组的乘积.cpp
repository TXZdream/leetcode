#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size()), right(nums.size()), result(nums.size());
        left[0] = nums[0];
        right[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i++) {
            left[i] = left[i - 1] * nums[i];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            int l = 0, r = 0;
            if (i == 0) {
                l = 1;
                r = right[i + 1];
            } else if (i == nums.size() - 1) {
                l = left[i - 1];
                r = 1;
            } else {
                l = left[i - 1];
                r = right[i + 1];
            }
            result[i] = l * r;
        }
        return result;
    }
};