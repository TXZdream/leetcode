#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comps(string c, string d) {
    if (c.size() == d.size()) {
        return c > d;
    } else if (c.size() > d.size()) {
        if (c.substr(0, d.size()) == d) {
            return comps(c.substr(d.size(), c.size()-d.size()), d);
        } else {
            return c.substr(0, d.size()) > d;
        }
    } else {
        if (d.substr(0, c.size()) == c) {
            return comps(c, d.substr(c.size(), d.size()-c.size()));
        } else {
            return c > d.substr(0, c.size());
        }
    }
}

bool comp(int a, int b) {
    string c = to_string(a), d = to_string(b);
    return comps(c, d);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ret;
        for (int i = 0; i < nums.size(); i++) {
            ret += to_string(nums[i]);
        }
        int zeroCnt = -1;
        for (int i = 0; i < ret.size(); i++) {
            if (ret[i] != '0') {
                zeroCnt = i;
                break;
            }
        }
        if (zeroCnt == -1) {
            return "0";
        }
        return ret.substr(zeroCnt, ret.size() - zeroCnt);
    }
};