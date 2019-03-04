#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, end = s.length() - 1;
        while (1) {
            if (front >= end) {
                break;
            }
            if ('A' <= s[front] && s[front] <= 'Z') {
                s[front] = s[front] + 'a' - 'A';
            }
            if ('A' <= s[end] && s[end] <= 'Z') {
                s[end] = s[end] + 'a' - 'A';
            }
            if (s[front] == s[end]) {
                front++;
                end--;
                continue;
            }
            if (!('a' <= s[front] && s[front] <= 'z' || '0' <= s[front] && s[front] <= '9')) {
                front++;
                continue;
            }
            if (!('a' <= s[end] && s[end] <= 'z' || '0' <= s[end] && s[end] <= '9')) {
                end--;
                continue;
            }
            // cout << s[front] << " " << s[end] << endl;
            return false;
        }
        return true;
    }
};