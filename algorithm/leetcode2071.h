//
// Created by Oliver on 2025/5/1.
//

#ifndef LEETCODE2071_H
#define LEETCODE2071_H

#include <algorithm>

#include "../util.h"

namespace LeetCode2071 {
    class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());

            vector<bool> visited(pills, false);
            return 0;
        }
    };

    void test() {
        vector<int> tasks = { 3,2,1 };
        vector<int> workers = { 0,3,3 };
        cout << Solution().maxTaskAssign(tasks, workers, 1, 1) << endl;
    }
}

#endif //LEETCODE2071_H
