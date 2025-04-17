//
// Created by Oliver on 2025/4/14.
//

#ifndef LEETCODE283_H
#define LEETCODE283_H

#include "../util.h"

namespace LeetCode283 {
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            if (nums.empty()) {
                return;
            }
            int slow = 0, fast = 0;
            while (fast < nums.size()) {
                if (nums[fast] == 0) {
                    fast++;
                    continue;
                }
                swap(nums[slow++], nums[fast++]);
            }
        }
    };

    void test() {
        vector<int> nums = {4,2,4,0,0,3,0,5,1,0};
        Solution().moveZeroes(nums);
        print(nums);
    }
}

#endif //LEETCODE283_H
