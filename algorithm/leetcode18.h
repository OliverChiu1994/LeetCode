//
// Created by Oliver on 2025/4/17.
//

#ifndef LEETCODE18_H
#define LEETCODE18_H

#include <algorithm>

#include "../util.h"

namespace LeetCode18 {
    class Solution {
    public:
        // 排序 + 递归  解决nSum和问题
        vector<vector<int>> nSumTarget(vector<int> nums, int n, int start, long long target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            if (n < 2 || nums.size() < n) {
                return res;
            }
            if (n == 2) {
                int left = start, right = nums.size() - 1;
                int firstNum = nums[left], secondNum = nums[right];
                long long sum = firstNum + secondNum;
                if (sum == target) {
                    res.push_back({firstNum, secondNum});
                    while (left < right && nums[left] == firstNum) {
                        left++;
                    }
                    while (left < right && nums[right] == secondNum) {
                        right--;
                    }
                } else if (sum < target) {
                    while (left < right && nums[left] == firstNum) {
                        left++;
                    }
                } else {
                    while (left < right && nums[right] == secondNum) {
                        right--;
                    }
                }
                return res;
            }
            for (int i = start; i < nums.size(); i++) {
                auto temp = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (auto &ele : temp) {
                    ele.push_back(nums[i]);
                    res.push_back(ele);
                }
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
            return res;
        }


        // 排序 + 双指针  传统方法
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            int pos4 = nums.size()-1;
            while (pos4 >= 3) {
                int forthNum = nums[pos4];
                int pos3 = pos4 - 1;
                while (pos3 >= 2) {
                    int thirdNum = nums[pos3];
                    int pos2 = pos3 - 1;
                    int pos1 = 0;
                    while (pos2 > pos1) {
                        int secondNum = nums[pos2];
                        int firstNum = nums[pos1];
                        // 注意这里不能写  int sum = forthNum + thirdNum + secondNum + firstNum;  可能存在整数溢出
                        long long sum = (long long)forthNum + thirdNum + secondNum + firstNum;
                        if (sum == target) {
                            res.emplace_back(vector<int>{ firstNum, secondNum, thirdNum, forthNum});
                            while (pos2 > pos1 && nums[pos2] == secondNum) {
                                pos2--;
                            }
                            while (pos2 > pos1 && nums[pos1] == firstNum) {
                                pos1++;
                            }
                        } else if (sum < target) {
                            while (pos2 > pos1 && nums[pos1] == firstNum) {
                                pos1++;
                            }
                        } else {
                            while (pos2 > pos1 && nums[pos2] == secondNum) {
                                pos2--;
                            }
                        }
                    }
                    do {
                        pos3--;
                    } while (pos3 >= 2 && nums[pos3] == thirdNum);
                }
                do {
                    pos4--;
                } while (pos4 >= 3 && nums[pos4] == forthNum);
            }
            return res;
        }
    };

    void test() {
        vector<int> nums { 1,0,-1,0,-2,2 };
        auto res = Solution().fourSum(nums, 0);
        print(res);

        cout << endl;
        auto res2 = Solution().nSumTarget(nums, 4, 0, 0);
        print(res2);
    }
}

#endif //LEETCODE18_H
