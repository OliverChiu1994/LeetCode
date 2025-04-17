//
// Created by Oliver on 2025/4/17.
//

#ifndef LEETCODE167_H
#define LEETCODE167_H

#include "../util.h"

namespace LeetCode167 {
    class Solution {
    public:
        // 双指针
        vector<int> twoSum(vector<int>& numbers, int target) {
            int l = 0, r = numbers.size() - 1;
            while (l < r) {
                if (numbers[l] + numbers[r] == target) {
                    return {l + 1, r + 1};
                } else if (numbers[l] + numbers[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }
            return {};
        }
    };

    void test() {
        vector<int> nums = {2,7,11,15};
        auto res = Solution().twoSum(nums, 9);
        print(res);
    }
}

#endif //LEETCODE167_H
