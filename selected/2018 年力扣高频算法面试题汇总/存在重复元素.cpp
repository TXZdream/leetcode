#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> pairs;
        for (int i = 0; i < nums.size(); i++) {
            if (pairs[nums[i]]++ != 0) {
                return true;
            }
        }
        return false;
    }
};