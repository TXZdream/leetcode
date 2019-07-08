#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> pairs1;
        for (int i = 0; i < nums1.size(); i++) {
            pairs1[nums1[i]]++;
        }
        vector<int> ret;
        for (int i = 0; i < nums2.size(); i++) {
            if (pairs1[nums2[i]]-- > 0) {
                ret.push_back(nums2[i]);
            }
        }
        return ret;
    }
};