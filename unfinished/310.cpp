#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<bool> > array(n);
        for (int i = 0; i < n; i++) {
            array[i].resize(n);
            for (int j = 0; j < n; j++) {
                array[i][j] = false;
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            array[edges[i].first][edges[i].second] = true;
            array[edges[i].second][edges[i].first] = true;
        }
    }
};