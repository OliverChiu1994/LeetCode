//
// Created by Oliver on 2025/5/7.
//

#ifndef LEETCODE743_H
#define LEETCODE743_H

#include <algorithm>

#include "../util.h"

namespace LeetCode743 {
    class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            const int INF = INT_MAX / 2;
            vector<vector<int>> lines(n, vector<int>(n, INF));
            for (const auto& line : times) {
                lines[line[0] - 1][line[1] - 1] = line[2];
            }
            vector<bool> visited(n, false);
            vector<int> dist(n, INF);
            dist[k - 1] = 0;
            for (int i = 0; i < n; i++) {
                int x = -1;
                for (int y = 0; y < n; y++) {
                    if (!visited[y] && (x == -1 || dist[y] < dist[x])) {
                        x = y;
                    }
                }
                visited[x] = true;
                for (int y = 0; y < n; y++) {
                    dist[y] = min(dist[y], dist[x] + lines[x][y]);
                }
            }
            int ans = *max_element(dist.begin(), dist.end());
            return ans == INF ? -1 : ans;
        }
    };

    void test() {
        vector<vector<int>> times{{2,1,1},{2,3,1},{3,4,1}};
        cout << Solution().networkDelayTime(times, 4, 2) << endl;
    }
}

#endif //LEETCODE743_H
