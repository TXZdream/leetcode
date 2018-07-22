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
    vector<Point> outerTrees(vector<Point>& points) {
        vector<Point> ret;
        int up = -1, down = -1, left = -1, right = -1;
        for (int i = 0; i < points.size(); i++) {
            if (up == -1 || points[i].y > up) {
                up = points[i].y;
            }
            if (down == -1 || points[i].y < down) {
                down = points[i].y;
            }
            if (left == -1 || points[i].x < left) {
                left = points[i].x;
            }
            if (right == -1 || points[i].x > right) {
                right = points[i].x;
            }
        }
        Point upleft(-1, -1), upright(-1, -1), downleft(-1, -1), downright(-1, -1), leftup(-1, -1), leftdown(-1, -1), rightup(-1, -1), rightdown(-1, -1);
        for (int i = 0; i < points.size(); i++) {
            if (points[i].y == up || points[i].y == down || points[i].x == left || points[i].x == right) {
                ret.push_back(points[i]);
            }
        }

        for (int i = 0; i < ret.size(); i++) {}
        return ret;
    }
};