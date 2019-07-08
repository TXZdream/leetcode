#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
            if (!(s[i] >= 'a' && s[i] <= 'z')) {
                i++;
                continue;
            }
            if (!(s[j] >= 'a' && s[j] <= 'z')) {
                j--;
                continue;
            }
            if (s[i] != s[j]) {
                return false;
            }
            i++; j--;
        }
        return true;
    }
};