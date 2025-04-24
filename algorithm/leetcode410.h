//
// Created by Oliver on 2025/4/22.
//

#ifndef LEETCODE410_H
#define LEETCODE410_H

#include "../util.h"

namespace LeetCode410 {
    class Solution {
    public:
        bool isValid(vector<int>& nums, int k, int sum) {
            int count = 1;
            int currentExtra = sum;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > sum) {
                    return false;
                }
                if (nums[i] > currentExtra) {
                    if (count++ > k) {
                        return false;
                    }
                    currentExtra = sum;
                    currentExtra -= nums[i];
                } else {
                    currentExtra -= nums[i];
                }
            }
            return count <= k;
        }

        int splitArray(vector<int>& nums, int k) {
            int left = 0, right = 1e9;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (isValid(nums, k, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
    };

    void test() {
        vector<int> v = {0};
        //cout << Solution().isValid(v, 2, 4) << endl;
        cout << Solution().splitArray(v, 1);
    }
}

#endif //LEETCODE410_H
