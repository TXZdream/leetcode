#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = -1;
        bool isSet = false;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == target) {
                    return target;
                }
                if (tmp > target) {
                    k--;
                } else {
                    j++;
                }
                if (!isSet || abs(tmp - target) < abs(sum - target)) {
                    sum = tmp;
                    isSet = true;
                }
            }
        }
        return sum;
    }
};