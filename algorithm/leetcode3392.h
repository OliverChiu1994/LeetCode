//
// Created by Oliver on 2025/4/27.
//

#ifndef LEETCODE3392_H
#define LEETCODE3392_H

#include <algorithm>

#include "../util.h"

namespace LeetCode3392 {
    class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int result = 0;
            for (int i = 0; i < nums.size() - 2; i++) {
                if (nums[i + 1] % 2) continue;
                if (nums[i + 1] / 2 == nums[i] + nums[i + 2]) {
                    result++;
                }
            }
            return result;
        }
    };
}

#endif //LEETCODE3392_H
