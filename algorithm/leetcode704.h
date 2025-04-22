//
// Created by Oliver on 2025/4/22.
//

#ifndef LEETCODE704_H
#define LEETCODE704_H

#include "../util.h"
namespace LeetCode704 {
    class Solution {
    public:
        // 左闭右开
        int search2(vector<int>& nums, int target) {
            int left = 0, right = nums.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid;
                }
            }
            return -1;
        }

        // 左闭右闭
        int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                }
            }
            return -1;
        }
    };

    void test() {
        vector<int> nums = {-1,0,3,5,9,12};
        cout << Solution().search2(nums, 2) << endl;
    }
}

#endif //LEETCODE704_H
