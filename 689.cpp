#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int> > max(nums.size() - k + 1, vector<int>(3));
        vector<vector<int> > order(nums.size() - k + 1, vector<int>(3));
        for (int i = 0; i < nums.size() - k + 1; i++) {
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += nums[nums.size() - i - k + j];
            }
            if (i == 0 || sum >= max[i - 1][0]) {
                max[i][0] = sum;
                order[i][0] = i;
            } else {
                max[i][0] = max[i - 1][0];
                order[i][0] = order[i - 1][0];
            }
            if (i < k) {
                max[i][1] = -1;
                max[i][2] = -1;
                order[i][1] = -1;
                order[i][2] = -1;
                continue;
            }

            if (i == k || sum + max[i - k][0] >= max[i - 1][1]) {
                max[i][1] = sum + max[i - k][0];
                order[i][1] = i;
            } else {
                max[i][1] = max[i - 1][1];
                order[i][1] = order[i - 1][1];
            }
            if (i < 2 * k) {
                max[i][2] = -1;
                order[i][2] = -1;
                continue;
            }

            if (i == 2 * k || sum + max[i - k][1] >= max[i - 1][2]) {
                max[i][2] = sum + max[i - k][1];
                order[i][2] = i;
            } else {
                max[i][2] = max[i - 1][2];
                order[i][2] = order[i - 1][2];
            }
        }
        // for (int i = 0; i <= nums.size() - k; i++) {
        //     cout << max[i][0] << " " << max[i][1] << " " << max[i][2] << "   " << order[i][0] << " " << order[i][1] << " " << order[i][2] << endl;
        // }
        vector<int> ret(3);
        ret[0] = order[nums.size() - k][2];
        ret[1] = order[ret[0] - k][1];
        ret[2] = order[ret[1] - k][0];
        for (int i = 0; i < 3; i++) {
            ret[i] = nums.size() - k - ret[i];
        }
        return ret;
    }
};