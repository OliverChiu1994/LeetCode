//
// Created by zhaogan on 2025/4/24.
//

#ifndef LEETCODE_LEETCODE2799_H
#define LEETCODE_LEETCODE2799_H

#include "../util.h"

namespace LeetCode2799 {
    class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int, int> source;
            for (int num : nums) {
                source[num]++;
            }
            int res = 0;
            unordered_map<int, int> cur;
            int left = 0, right = 0;
            while (right < nums.size()) {
                cur[nums[right++]]++;

                // 缩小窗口
                while(cur.size() == source.size()) {
                    res += nums.size() - right + 1;
                    int num = nums[left++];
                    cur[num]--;
                    if (cur[num] == 0) {
                        cur.erase(num);
                    }
                }
            }
            return res;
        }
    };

    void test() {
        vector<int> nums { 5,5,5,5 };
        cout << Solution().countCompleteSubarrays(nums);
    }
}

#endif //LEETCODE_LEETCODE2799_H
