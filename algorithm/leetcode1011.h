//
// Created by Oliver on 2025/4/22.
//

#ifndef LEETCODE1011_H
#define LEETCODE1011_H

#include "../util.h"

namespace LeetCode1011 {
    class Solution {
    public:
        bool canShip(vector<int>& weights, int maxWeight, int days) {
            int n = weights.size();
            int currentExtra = maxWeight;
            int count = 1;
            for (int i = 0; i < n; i++) {
                if (weights[i] > maxWeight) {
                    return false;
                }
                if (currentExtra < weights[i]) {
                    if (count++ > days) {
                        return false;
                    }
                    currentExtra = maxWeight;
                    currentExtra -= weights[i];
                } else {
                    currentExtra -= weights[i];
                }
            }
            return count <= days;
        }

        int shipWithinDays(vector<int>& weights, int days) {
            int left = 0, right = 5 * 500 * 10000;
            // 左闭右闭
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (canShip(weights, mid, days)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
    };

    void test() {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        cout << Solution().shipWithinDays(v, 5);
        //cout << Solution().canShip(v, 11, 5) << endl;
    }
}

#endif //LEETCODE1011_H
