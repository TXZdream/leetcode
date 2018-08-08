#include<iostream>
#include<vector>
using namespace std;


// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) {
            return points.size();
        }
        int max = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    continue;
                }
                int cur = 2;
                for (int k = j + 1; k < points.size(); k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (points[k].x == points[j].x && points[k].y == points[j].y) {
                        continue;
                    }
                    if (points[i].x == points[k].x && points[i].y == points[k].y) {
                        continue;
                    }
                    Point a(points[j].x - points[i].x, points[j].y - points[i].y);
                    Point b(points[j].x - points[k].x, points[j].y - points[k].y);
                    if (getXPower(&a, &b) == 0) {
                        cur++;
                    }
                }
                if (cur > max) {
                    max = cur;
                }
            }
        }
        return max;
    }
private:
    static int getXPower(Point* a, Point* b) {
        return double(a->x) * double(b->y) - double(a->y) * double(b->x);
    }
};