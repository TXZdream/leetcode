#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        vector<int> next(needle.size());
        next[0] = -1;
        if (next.size() >= 1) {
            next[1] = 0;
        }
        for (int i = 2; i < needle.size(); i++) {
            bool flag = false;
            int tmp = next[i - 1];
            while (tmp >= 0) {
                if (needle[tmp] == needle[i-1]) {
                    next[i] = tmp + 1;
                    break;
                } else {
                    tmp = next[tmp];
                }
            }
            if (tmp < 0) {
                next[i] = 0;
            }
            // cout << next[i] << endl;
        }
        for (int i = 0; i < haystack.size();) {
            for (int j = 0; j < needle.size();) {
                if (needle[j] == haystack[i]) {
                    i++; j++;
                } else {
                    if (next[j] == -1) {
                        i++; j = 0;
                    } else {
                        j = next[j];
                    }
                }
            }
            return i - needle.size();
        }
        return -1;
    }
};