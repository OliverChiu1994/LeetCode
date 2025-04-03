//
// Created by Oliver on 2025/3/31.
//

#ifndef LEETCODE695_H
#define LEETCODE695_H

#include <array>
#include <iostream>
#include <variant>
#include <vector>
using namespace std;
namespace LeetCode685 {
    class Solution {
    public:
        const vector<vector<int>> walk {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        int getArea(vector<vector<int>>& grid, vector<vector<bool>>& visit, int i, int j) {
            if (grid[i][j] == 0 || visit[i][j]) {
                return 0;
            }
            int area = 1;
            visit[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                int ni = i + walk[k][0];
                int nj = j + walk[k][1];
                if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) {
                    continue;
                }
                area += getArea(grid, visit, ni, nj);
            }
            return area;
        }

        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            int res = 0;
            vector<vector<bool>> visit(n, vector<bool>(m, false));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 0) {
                        visit[i][j] = true;
                        continue;
                    }
                    if (visit[i][j] == true) {
                        continue;
                    }
                    int curArea = getArea(grid, visit, i, j);
                    res = max(res, curArea);
                }
            }
            return res;
        }
    };

    void test() {
        // vector<vector<int>> grid = {
        //     {0,0,1,0,0,0,0,1,0,0,0,0,0},
        //     {0,0,0,0,0,0,0,1,1,1,0,0,0},
        //     {0,1,1,0,1,0,0,0,0,0,0,0,0},
        //     {0,1,0,0,1,1,0,0,1,0,1,0,0},
        //     {0,1,0,0,1,1,0,0,1,1,1,0,0},
        //     {0,0,0,0,0,0,0,0,0,0,1,0,0},
        //     {0,0,0,0,0,0,0,1,1,1,0,0,0},
        //     {0,0,0,0,0,0,0,1,1,0,0,0,0}};

        vector<vector<int>> grid = {
            {0,0,0,0,0,0,0,0}
        };

        Solution solution;
        cout << solution.maxAreaOfIsland(grid) << endl;

    }
}
#endif //LEETCODE695_H
