//
// Created by Oliver on 2025/4/7.
//

#ifndef LEETCODE47_H
#define LEETCODE47_H

#include <algorithm>

#include "../util.h"

namespace LeetCode47 {
    class Solution {
    public:
        vector<bool> visited;
        void traceBack(vector<vector<int>> &res, vector<int> &nums, vector<int> &cur, int index) {
            if (index == nums.size()) {
                res.push_back(cur);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                    continue;
                }
                visited[i] = true;
                cur.push_back(nums[i]);
                traceBack(res, nums, cur, index + 1);
                cur.pop_back();
                visited[i] = false;
            }
        }

        vector<vector<int>> permuteUnique(vector<int>& nums) {
            visited.resize(nums.size(), false);
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            vector<int>cur;
            traceBack(res, nums, cur, 0);
            return res;
        }
    };

    void test() {
        Solution s;
        vector<int> nums{1,1,2};
        vector<vector<int>> res = s.permuteUnique(nums);
        print(res);
    }
}

#endif //LEETCODE47_H
