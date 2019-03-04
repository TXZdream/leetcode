#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        return pyramid(bottom, "", true, 0, allowed);
    }
private:
    bool pyramid(string bottom, string curr, bool isLeft, int index, vector<string>& allowed) {
        if (bottom.size() == 1) {
            return true;
        }
        int left = index, right = left + 1;
        for (int i = 0; i < allowed.size(); i++) {
            if (bottom[left] == allowed[i][0] && bottom[right] == allowed[i][1]) {
                bool flag;
                curr = curr + allowed[i][2];
                if (curr.size() == bottom.size() - 1) {
                    flag = pyramid(curr, "", !isLeft, isLeft?curr.size()-2:0, allowed);
                } else {
                    flag = pyramid(bottom, curr, isLeft, isLeft?index+1:index-1, allowed);
                }
                if (flag) {
                    return true;
                } else {
                    curr.resize(curr.size() - 1);
                }
            }
        }
        return false;
    }
};