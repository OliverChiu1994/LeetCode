//
// Created by Oliver on 2025/5/11.
//

#ifndef LEETCODE1550_H
#define LEETCODE1550_H

#include "../util.h"

namespace LeetCode1550 {
    class Solution {
    public:
        bool threeConsecutiveOdds(vector<int>& arr) {
            if (arr.size() < 3) return false;
            int left = 0, right = 0;
            while (right < arr.size()) {
                if (arr[right] % 2) {
                    if (right >= left + 2) {
                        return true;
                    }
                } else {
                    left = right + 1;
                }
                right++;
            }
            return false;
        }
    };

    void test() {
        vector<int> nums {1,2,34,3,4,5,7,23,12};
        cout << Solution().threeConsecutiveOdds(nums) << endl;
    }
}

#endif //LEETCODE1550_H
