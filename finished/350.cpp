#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int index1 = 0, index2 = 0;
        while(1) {
            if (index1 >= nums1.size() || index2 >= nums2.size()) {
                break;
            }
            if (nums1[index1] == nums2[index2]) {
                ret.push_back(nums1[index1]);
                index1++;
                index2++;
                continue;
            }
            if (nums1[index1] > nums2[index2]) {
                index2++;
                continue;
            }
            index1++;
        }
        return ret;
    }
};