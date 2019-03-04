#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int front = 0, end = nums.size() - 1;
        while (front <= end) {
            int mid = (front + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                if (mid == 0) {
                    return mid;
                }
                if (mid - 1 >= 0 && nums[mid - 1] < target) {
                    return mid;
                }
                end = mid - 1;
                continue;
            }
            if (mid == nums.size() - 1) {
                return nums.size();
            }
            if (mid + 1 < nums.size() && nums[mid + 1] > target) {
                return mid + 1;
            }
            front = mid + 1;
        }
    }
};