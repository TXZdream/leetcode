#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        nums.clear();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                nums.push_back(i);
            }
        }
    }
};