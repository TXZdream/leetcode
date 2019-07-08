#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxNum = nums[0];
        long long minNum = nums[0];
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            long long tmpMax = maxNum, tmpMin = minNum;
            maxNum = max((long long)nums[i], max(tmpMax * nums[i], tmpMin * nums[i]));
            minNum = min((long long)nums[i], min(tmpMax * nums[i], tmpMin * nums[i]));
            if (maxNum > ret) {
                ret = maxNum;
            }
        }
        return ret;
    }
};