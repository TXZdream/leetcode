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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0 || newInterval.start > intervals[intervals.size()-1].end) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<Interval> ret;
        int start, endPos;
        if (newInterval.start <= intervals[0].start) {
            start = newInterval.start;
            endPos = 0;
        } else {
            for (int i = 0; i < intervals.size(); i++) {
                if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) {
                    start = intervals[i].start;
                    endPos = i;
                    break;
                }
                if (i != intervals.size()-1 && (newInterval.start > intervals[i].end && newInterval.start < intervals[i+1].start)) {
                    ret.push_back(intervals[i]);
                    start = newInterval.start;
                    endPos = i;
                    break;
                }
                ret.push_back(intervals[i]);
            }
        }
        ret.push_back(intervals[0]);
        ret[ret.size()-1].start = start;

        if (newInterval.end >= intervals[intervals.size()-1].end) {
            ret[ret.size()-1].end = newInterval.end;
        } else {
            for (int i = endPos; i < intervals.size(); i++) {
                if (i == 0 && newInterval.end < intervals[0].start) {
                    ret[0].end = newInterval.end;
                    endPos = 0;
                    break;
                }
                if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) {
                    ret[ret.size()-1].end = intervals[i].end;
                    endPos = i + 1;
                    break;
                }
                if (i != intervals.size()-1 && (newInterval.end > intervals[i].end && newInterval.end < intervals[i+1].start)) {
                    ret[ret.size()-1].end = newInterval.end;
                    endPos = i + 1;
                    break;
                }
            }
            for (int i = endPos; i < intervals.size(); i++) {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};