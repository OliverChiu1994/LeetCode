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

    // 遍历实现
    class Solution2 {
    private:
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited;
        int n;
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            n = nums.size();
            visited.resize(n, false);

            traverse(nums);
            return res;
        }

        void traverse(vector<int>& nums) {
            if (cur.size() == n) {
                res.push_back(vector<int>(cur.begin(), cur.end()));
                return;
            }
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    continue;
                }
                visited[i] = true;
                cur.push_back(nums[i]);

                traverse(nums);

                visited[i] = false;
                cur.pop_back();
            }
        }
    };

    // 递归实现
    class Solution3 {
    public:
        vector<vector<int>> process(vector<int>& nums, int start) {
            vector<vector<int>> res;
            if (start == nums.size() - 1) {
                res.emplace_back(1, nums[start]);
                return res;
            }
            auto cur = process(nums, start + 1);
            for (const auto& v : cur) {
                vector<int> temp{nums[start]};
                for (int num : v) {
                    temp.push_back(num);
                }
                res.emplace_back(temp);
            }
            for (int i = start + 1; i < nums.size(); i++) {
                swap(nums[i], nums[start]);
                auto cur2 = process(nums, start + 1);
                for (const auto& v : cur2) {
                    vector<int> temp{nums[start]};
                    for (int num : v) {
                        temp.push_back(num);
                    }
                    res.emplace_back(temp);
                }
                swap(nums[i], nums[start]);
            }
            return res;
        }
        vector<vector<int>> permute(vector<int>& nums) {
            return process(nums, 0);
        }
    };

    void test() {
        Solution3 s;
        vector<int> nums{1, 2, 3};
        // vector<vector<int>> cur1 = s.permute(nums);
        // print(cur1);
        // cout << endl;
        // vector<vector<int>> cur2 = s.permute2(nums);
        // print(cur2);

        print(s.permute(nums));
    }
}

#endif //LEETCODE46_H
