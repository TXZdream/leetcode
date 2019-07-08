#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ret;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i >= m) {
                ret.push_back(nums2[j++]);
                continue;
            }
            if (j >= n) {
                ret.push_back(nums1[i++]);
                continue;
            }
            if (nums1[i] <= nums2[j]) {
                ret.push_back(nums1[i++]);
            } else {
                ret.push_back(nums2[j++]);
            }
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = ret[i];
        }
    }
};