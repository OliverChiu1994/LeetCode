//
// Created by Oliver on 2025/4/3.
//

#ifndef LEETCODE55_H
#define LEETCODE55_H

#include "../util.h"

namespace LeetCode55 {
    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            vector<bool> dp(n, false);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                for (int len = 1; len <= nums[i] && len + i < n; len++) {
                    dp[i + len] = dp[i];
                }
            }
            return dp[n - 1];
        }
    };

    void test() {
        Solution s;
        vector<int> v = {0,2,3};
        print(s.canJump(v));
    }
}
#endif //LEETCODE55_H
