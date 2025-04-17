//
// Created by Oliver on 2025/4/9.
//

#ifndef LEETCODE27_H
#define LEETCODE27_H

#include "../util.h"

namespace LeetCode27 {
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int l = 0, r = 0;
            while (r < nums.size()) {
                if (nums[r] != val) {
                    nums[l] = nums[r];
                    l++;
                }
                r++;
            }
            nums.resize(l);
            return l;
        }

        int removeElement2(vector<int>& nums, int val) {
            int l = 0, r = 0;
            while (l < nums.size()) {
                if (nums[l] != val) {
                    l++;
                    continue;
                }
                // nums[l] == val
                r = l + 1;
                while (r < nums.size() && nums[r] == val) {
                    r++;
                }
                if (r < nums.size()) {
                    swap(nums[l], nums[r]);
                    l++;
                } else {
                    break;
                }
            }
            nums.resize(l);
            return l;
        }
    };

    void test() {
        vector<int> nums = {0,1,2,2,3,0,4,2};
        print(Solution().removeElement(nums, 2));
        print(nums);
    }
}

#endif //LEETCODE27_H
