#include<iostream>
#include<vector>
using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        bool flag = true;
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (!flag) break;
            flag = false;
            for (int j = intervals.size() - 1; j >= i + 1; j--) {
                if (intervals[j].start < intervals[j - 1].start) {
                    flag = true;
                    int tmp = intervals[j-1].start;
                    intervals[j-1].start = intervals[j].start;
                    intervals[j].start = tmp;
                    tmp = intervals[j-1].end;
                    intervals[j-1].end = intervals[j].end;
                    intervals[j].end = tmp;
                }
            }
        }

        vector<Interval> ret;
        ret.push_back(intervals[0]);
        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (end >= intervals[i].start) {
                if (intervals[i].end > end) {
                    end = intervals[i].end;
                }
            } else {
                ret[ret.size()-1].end = end;
                ret.push_back(intervals[i]);
                end = intervals[i].end;
            }
        }
        ret[ret.size()-1].end = end;
        return ret;
    }
};
