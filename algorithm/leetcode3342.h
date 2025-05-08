//
// Created by Oliver on 2025/5/8.
//

#ifndef LEETCODE3342_H
#define LEETCODE3342_H

#include "../util.h"

namespace LeetCode3342 {
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
        int minTimeToReach(vector<vector<int>>& moveTime) {
            size_t n = moveTime.size();
            size_t m = moveTime[0].size();
            const int INF = INT_MAX / 2;
            vector<vector<int>> distance(n, vector<int>(m, INF));
            distance[0][0] = 0;

            const vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            priority_queue<State> pq;
            pq.push(State(0, 0, 0));
            while (!pq.empty()) {
                State s = pq.top();
                pq.pop();
                if (visited[s.x][s.y]) {
                    continue;
                }
                visited[s.x][s.y] = true;
                for (const auto direction : directions) {
                    int next_x = s.x + direction[0];
                    int next_y = s.y + direction[1];
                    if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
                        continue;
                    }
                    int foot = (next_x + next_y) % 2 ? 1 : 2;
                    int cur = max(moveTime[next_x][next_y], distance[s.x][s.y]) + foot;
                    if (cur < distance[next_x][next_y]) {
                        distance[next_x][next_y] = cur;
                        pq.push(State(next_x, next_y, cur));
                    }
                }
            }
            return distance[n - 1][m - 1];
        }
    };

    // 传统迪杰斯特拉方法，超时
    class Solution2 {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            const int INF = INT_MAX / 2;
            const vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            size_t n = moveTime.size();
            size_t m = moveTime[0].size();
            vector<vector<int>> dist(n, vector<int>(m, INF));
            vector<vector<bool>> visted(n, vector<bool>(m, false));
            dist[0][0] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int r = -1;
                    int c = -1;
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < m; y++) {
                            if (!visted[x][y] && ((r == -1 || c == -1) || dist[x][y] < dist[r][c])) {
                                r = x;
                                c = y;
                            }
                        }
                    }
                    visted[r][c] = true;
                    for (const auto &d : directions) {
                        int nx = r + d[0];
                        int ny = c + d[1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            int foot = (nx + ny) % 2 ? 1 : 2;
                            int cur = max(dist[r][c], moveTime[nx][ny]) + foot;
                            dist[nx][ny] = min(cur, dist[nx][ny]);
                        }
                    }
                }
            }
            return dist[n-1][m-1];
        }
    };

    void test() {
        vector<vector<int>> moveTime{{25,44},{4,2}};
        cout << Solution().minTimeToReach(moveTime) << endl;
    }
}

#endif //LEETCODE3342_H
