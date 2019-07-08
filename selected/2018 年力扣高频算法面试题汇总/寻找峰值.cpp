#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            if (start == end) {
                if ((start == 0 && nums[0] > nums[1]) || (end == nums.size() - 1 && nums[end] > nums[end - 1])) {
                    return start;
                }
                if (nums[start] < nums[start - 1] || nums[end] < nums[end + 1]) {
                    return -1;
                }
            }
            int mid = (start + end) / 2;
            if (mid == 0) {
                if (nums[0] > nums[1]) {
                    return 0;
                } else {
                    start = 1;
                    continue;
                }
            }
            if (mid == nums.size() - 1) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                } else {
                    end = mid - 1;
                    continue;
                }
            }
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
                continue;
            }
            end = mid - 1;
        }
        return -1;
    }
};