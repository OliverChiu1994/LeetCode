//
// Created by Oliver on 2025/4/3.
//

#ifndef LEETCODE45_H
#define LEETCODE45_H

#include <vector>
#include "util.h"

namespace LeetCode45 {
    class Solution {
    public:
        int jump(vector<int>& nums) {
            // 贪心
            int maxPos = 0, end = 0, step = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (maxPos >= i) {
                    maxPos = max(maxPos, i + nums[i]);
                    if (i == end) {
                        end = maxPos;
                        step++;
                    }
                }
            }
            return step;
        }

        int jump2(vector<int>& nums) {
            vector<int>dp(nums.size(),0);
            dp[0] = 0;
            for (int i = 1; i < nums.size(); i++) {
                int curMin = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if (j + nums[j] < i) {
                        continue;
                    }
                    curMin = min(curMin, dp[j] + 1);
                }
                dp[i] = curMin;
            }
            return dp[nums.size()-1];
        }
    };

    void test() {
        vector<int> nums{2,3,0,1,4};
        Solution s;
        print(s.jump(nums));
    }
}

#endif //LEETCODE45_H
