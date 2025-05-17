//
// Created by zhaogan on 2025/5/12.
//

#ifndef LEETCODE_LEETCODE2094_H
#define LEETCODE_LEETCODE2094_H

#include "../util.h"

namespace LeetCode2094 {
    class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            vector<int> res;
            unordered_set<int> set;
            for (int i = 0; i < digits.size(); i++) {
                for (int j = 0; j < digits.size(); j++) {
                    for (int k = 0; k < digits.size(); k++) {
                        if (i == j || i == k || j == k) {
                            continue;
                        }
                        int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (number % 2 == 0 && number >= 100) {
                            set.insert(number);
                        }
                    }
                }
            }
            for (int num : set) {
                res.push_back(num);
            }
            sort(res.begin(), res.end());
            return res;
        }
    };
}
#endif //LEETCODE2094_H
