//
// Created by Oliver on 2025/4/17.
//

#ifndef LEETCODE80_H
#define LEETCODE80_H

#include "../util.h"

namespace LeetCode80 {
    class Solution {
    public:
        // 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

        // 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。


        // 双指针 ,[0,l]表示符合条件的
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() <= 2) {
                return nums.size();
            }
            int left = 0, right = 0, count = 0;
            while (right < nums.size()) {
                // 符合条件，加入
                if (nums[right] != nums[left]) {
                    nums[++left] = nums[right];
                } else if (left < right && count < 2) {  //  符合条件，加入
                    nums[++left] = nums[right];
                }
                count++;
                right++;
                if (right < nums.size() && nums[right] != nums[right - 1]) {
                    count = 0;
                }
            }
            nums.resize(left + 1);
            return left + 1;
        }

        // 扩展，删除数组中的重复项，最多出现n次
        int removeNDuplicates(vector<int>& nums, int time) {
            if (nums.empty()) {
                return 0;
            }
            int left = 0, right = 0, count = 0;
            while (right < nums.size()) {
                if (nums[right] != nums[left]) {
                    ++left;
                    nums[left] = nums[right];
                } else if (left < right && count < time) {
                    ++left;
                    nums[left] = nums[right];
                }
                count++;
                right++;
                if (right < nums.size() && nums[right] != nums[right - 1]) {
                    count = 0;
                }
            }
            nums.resize(left + 1);
            return left + 1;
        }
    };

    void test() {
        vector<int> nums = { 1,1,1,2,2,3 };
        cout << Solution().removeNDuplicates(nums, 1) << endl;
        print(nums);
    }
}

#endif //LEETCODE80_H
