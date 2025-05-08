//
// Created by Oliver on 2025/5/7.
//

#ifndef LEETCODE3341_H
#define LEETCODE3341_H

#include "../util.h"

namespace LeetCode3341 {
    struct State {
        int x;
        int y;
        int dis;

        State(int x_, int y_, int dis_) : x(x_), y(y_), dis(dis_) {};

        bool operator < (const State& s) const {
            return dis > s.dis;
        }
    };
    class Solution {
    public:
        // 优先队列
        int minTimeToReach(vector<vector<int>>& moveTime) {
            size_t n = moveTime.size();
            size_t m = moveTime[0].size();
            const int INF = INT_MAX / 2;
            vector<vector<int>>distance(n, vector<int>(m, INF));
            vector<vector<bool>>visited(n, vector<bool>(m, false));
            const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            priority_queue<State> pq;
            pq.push(State(0, 0, 0));
            distance[0][0] = 0;

            while (!pq.empty()) {
                State s = pq.top();
                pq.pop();
                if (visited[s.x][s.y]) {
                    continue;
                }
                visited[s.x][s.y] = true;
                for (const auto& dir : dirs) {
                    int nextX = s.x + dir[0];
                    int nextY = s.y + dir[1];
                    if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                        int cur = max(distance[s.x][s.y], moveTime[nextX][nextY]) + 1;
                        if (cur < distance[nextX][nextY]) {
                            distance[nextX][nextY] = cur;
                            pq.push(State(nextX, nextY, cur));
                        }
                    }
                }
            }
            return distance[n - 1][m - 1];
        }
    };

    class Solution2 {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size();
            int m = moveTime[0].size();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            const int INF = INT_MAX / 2;
            const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            vector<vector<int>> dist(n, vector<int>(m, INF));
            dist[0][0] = moveTime[0][0];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int r = -1;
                    int c = -1;
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < m; y++) {
                            if (!visited[x][y] && ((r == -1 || c == -1) || dist[x][y] < dist[r][c])) {
                                r = x;
                                c = y;
                            }
                        }
                    }
                    visited[r][c] = true;
                    for (const auto& d : dirs) {
                        int nextX = r + d[0];
                        int nextY = c + d[1];
                        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                            int cur = max(dist[r][c], moveTime[nextX][nextY]) + 1;
                            dist[nextX][nextY] = min(cur, dist[nextX][nextY]);
                        }
                    }
                }
            }
            return dist[n - 1][m - 1];
        }
    };

    void test() {
        vector<vector<int>> moveTime = {{15,58},{67,4}};
        cout << Solution().minTimeToReach(moveTime) << endl;
    }
}

#endif //LEETCODE3341_H
