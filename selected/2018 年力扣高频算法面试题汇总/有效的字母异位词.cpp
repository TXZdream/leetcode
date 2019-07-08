#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.size() != s.size()) {
            return false;
        }
        vector<int> nums(26);
        for (int i = 0; i < 26; i++) {
            nums[i] = 0;
        }
        for (int i = 0; i < s.size(); i++) {
            nums[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            nums[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (nums[i] != 0) {
                return false;
            }
        }
        return true;
    }
};