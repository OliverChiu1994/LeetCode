//
// Created by Oliver on 2025/4/17.
//

#ifndef LEETCODE15_H
#define LEETCODE15_H

#include <algorithm>

#include "../util.h"

namespace LeetCode15 {
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int pos3 = nums.size() - 1;
            if (nums.size() < 3) {
                return vector<vector<int>>();
            }
            vector<vector<int>> res;
            int lastEle = nums[pos3];
            while (pos3 >= 2) {
                int pos1 = 0;
                int pos2 = pos3 - 1;
                while (pos1 < pos2) {
                    int firstEle = nums[pos1];
                    int secondEle = nums[pos2];
                    int sum = firstEle + secondEle + lastEle;
                    if (sum == 0) {
                        res.push_back(vector<int>{firstEle, secondEle, lastEle});
                        while (pos1 < pos2 && nums[pos1] == firstEle) {
                            pos1++;
                        }
                        while (pos1 < pos2 && nums[pos2] == secondEle) {
                            pos2--;
                        }
                    } else if (sum < 0) {
                        while (pos1 < pos2 && nums[pos1] == firstEle) {
                            pos1++;
                        }
                    } else {
                        while (pos1 < pos2 && nums[pos2] == secondEle) {
                            pos2--;
                        }
                    }
                }
                // 下面的do while还可以写成下面这样：
                // while (pos3-- >= 2 && nums[pos3] == lastEle) {}

                do {
                    pos3--;
                } while (pos3 >= 2 && nums[pos3] == lastEle);
                lastEle = nums[pos3];
            }
            return res;
        }
    };

    void test() {
        vector<int> nums = {0,0,0};
        auto res = Solution().threeSum(nums);
        print(res);
    }
}

#endif //LEETCODE15_H
