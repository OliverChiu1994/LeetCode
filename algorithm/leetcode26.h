//
// Created by Oliver on 2025/4/9.
//

#ifndef LEETCODE26_H
#define LEETCODE26_H

#include "../util.h"

namespace LeetCode26 {
    class Solution {
    public:
        // 快慢指针，一个负责遍历，一个负责记录
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) return 0;
            int l = 0, r = 0;
            while (r < nums.size()) {
                if (nums[r] != nums[l]) {
                    nums[++l] = nums[r];
                }
                r++;
            }
            nums.resize(++l);
            return l;
        }

        int removeDuplicates2(vector<int>& nums) {
            int l = 0, r = 0;
            while (r < nums.size() && l + 1 < nums.size()) {
                if (nums[r] <= nums[l]) {
                    r++;
                    continue;
                }
                // nums[r] > nums[l]
                swap(nums[l + 1], nums[r]);
                l++;
                r++;
            }
            nums.resize(l + 1);
            return l + 1;
        }
    };

    void test() {
        vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
        print(Solution().removeDuplicates(nums));
        print(nums);
    }
}

#endif //LEETCODE26_H
