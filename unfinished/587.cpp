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
        vector<bool> isAdded(points.size());
        int leftdown = -1;
        for (int i = 0; i < points.size(); i++) {
            isAdded[i] = false;
            if (leftdown == -1 || (points[i].x < points[leftdown].x && points[i].y < points[leftdown].y)) {
                leftdown = i;
            }
        }
        isAdded[leftdown] = true;
        ret.push_back(points[leftdown]);
        Point raw(0, 0);
        int topIndex = leftdown;
        while (true) {
            int xmultiply = 0;
            int currentIndex = -1;
            for (int i = 0; i < points.size(); i++) {
                if (!isAdded[i]) {
                    Point test(points[i].x - points[topIndex].x, points[i].y - points[topIndex].y);
                    int tmp = XMultiply(raw, test);
                    if (tmp == 0) {
                        isAdded[i] = true;
                        ret.push_back(points[i]);
                        break;
                    }
                    if (currentIndex == -1 || (xmultiply > 0 && xmultiply < tmp)) {
                        currentIndex = i;
                        xmultiply = tmp;
                    }
                }
            }
            if (currentIndex == -1) {
                break;
            }
            raw.x = points[currentIndex].x - points[topIndex].x;
            raw.y = points[currentIndex].y - points[topIndex].y;
            topIndex = currentIndex;
            isAdded[currentIndex] = true;
        }
        return ret;
    }
private:
    static int XMultiply(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }
};