//
// Created by Oliver on 2025/4/2.
//

#ifndef LEETCODE39_H
#define LEETCODE39_H

#include <algorithm>
#include <vector>

#include "../util.h"

using namespace std;

namespace LeetCode39 {
    class Solution {
    public:
        static vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            set<vector<int>> sets;
            vector<int> lessNum;
            for (int n : candidates) {
                if (n <= target) {
                    lessNum.push_back(n);
                }
            }
            if (lessNum.empty()) {
                return res;
            }
            sort(lessNum.begin(), lessNum.end());
            for (int i = 0; i < lessNum.size(); i++) {
                if (i > 0 && lessNum[i] == lessNum[i - 1]) {
                    continue;
                }
                int curNum = lessNum[i];
                if (curNum == target) {
                    vector<int> temp {curNum};
                    res.push_back(temp);
                    continue;
                }
                for (const auto &item : combinationSum(candidates, target - curNum)) {
                    vector<int> temp { item };
                    temp.push_back(curNum);
                    sort(temp.begin(), temp.end());
                    sets.insert(temp);
                }
            }
            for (const auto &item : sets) {
                res.emplace_back(item);
            }
            return res;
        }

        static void dfs(vector<int>& candidates, int target, int index, vector<vector<int>>& res, vector<int>& temp) {
            if (index == candidates.size()) {
                return;
            }
            if (target == 0) {
                res.emplace_back(temp);
                return;
            }
            // 不选中
            dfs(candidates, target, index + 1, res, temp);
            // 选中
            if (target >= candidates[index]) {
                temp.emplace_back(candidates[index]);
                dfs(candidates, target - candidates[index], index, res, temp);
                temp.pop_back();
            }
        }

        static vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            if (candidates.empty()) {
                return {};
            }
            vector<vector<int>> res;
            vector<int>temp;
            dfs(candidates, target, 0, res, temp);
            return res;
        }
    };

    inline void test() {
        vector<int> cand = {2,3,6,7};
        vector<vector<int>> grid = Solution::combinationSum2(cand, 7);
        print(grid);
    }
}

#endif //LEETCODE39_H
