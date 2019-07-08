#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        for (int i = 0; i <= two; i++) {
            if (nums[i] == 0 && i != zero) {
                nums[i--] = nums[zero];
                nums[zero++] = 0;
                continue;
            }
            if (nums[i] == 2) {
                nums[i--] = nums[two];
                nums[two--] = 2;
                continue;
            }
        }
    }
};