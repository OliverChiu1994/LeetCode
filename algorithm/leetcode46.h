//
// Created by Oliver on 2025/4/7.
//

#ifndef LEETCODE46_H
#define LEETCODE46_H

#include "../util.h"

namespace LeetCode46 {
    // 全排列
    // 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
    class Solution {
        int n;
    public:
        void backTrack(vector<vector<int>> &res, vector<int>& nums, int first) {
            if (first == n) {
                res.push_back(nums);
                return;
            }
            for (int i = first; i < n; i++) {
                swap(nums[first], nums[i]);
                backTrack(res, nums, first + 1);
                swap(nums[first], nums[i]);
            }
        }

        vector<vector<int>> permute(vector<int>& nums) {
            n = nums.size();
            vector<vector<int>> res;
            backTrack(res, nums, 0);
            return res;
        }

        // 回溯2
        vector<bool> visited;
        void backTrack2(vector<vector<int>>& res, vector<int>& nums, int first, vector<int>& cur) {
            if (first == n) {
                res.push_back(cur);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    continue;;
                }
                visited[i] = true;
                cur.push_back(nums[i]);
                backTrack2(res, nums, first + 1, cur);
                cur.pop_back();
                visited[i] = false;
            }
        }
        vector<vector<int>> permute2(vector<int>& nums) {
            n = nums.size();
            visited.resize(n);
            vector<vector<int>> res;
            vector<int> cur;
            backTrack2(res, nums, 0, cur);
            return res;
        }
    };

    void test() {
        Solution s;
        vector<int> nums{1, 2, 3};
        vector<vector<int>> cur1 = s.permute(nums);
        print(cur1);
        cout << endl;
        vector<vector<int>> cur2 = s.permute2(nums);
        print(cur2);
    }
}

#endif //LEETCODE46_H
