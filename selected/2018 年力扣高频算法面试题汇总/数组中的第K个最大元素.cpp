#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

private:
    int findKthLargest(vector<int>& nums, int from, int to, int k) {
        cout << from << " " << to << " " << k << endl;
        if (from == to) {
            return nums[from];
        }
        int i = from, j = to;
        int flag = nums[i];
        while (i < j) {
            while (i < j && nums[j] <= flag) {
                j--;
            }
            if (i == j) {
                break;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] >= flag) {
                i++;
            }
            if (i == j) {
                break;
            }
            nums[j] = nums[i];
        }
        nums[i] = flag;
        if (i - from + 1 == k) {
            return flag;
        }
        if (i - from + 1 > k) {
            return findKthLargest(nums, from, i - 1, k);
        }
        return findKthLargest(nums, i + 1, to, k - (i - from + 1));
    }
};