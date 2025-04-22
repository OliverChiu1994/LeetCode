//
// Created by Oliver on 2025/4/22.
//

#ifndef LEETCODE875_H
#define LEETCODE875_H

#include <algorithm>

#include "../util.h"

namespace LeetCode875 {
    class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            sort(piles.begin(), piles.end());
            int left = 1, right = piles[piles.size() - 1];
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int count = 0;
                for (int i = 0; i < piles.size(); i++) {
                    if (piles[i] % mid) {
                        count++;
                    }
                    count += piles[i] / mid;
                    if (count > h) {
                        left = mid + 1;
                        break;
                    }
                }
                if (count > h) {
                    left = mid + 1;
                } else if (count < h) {
                    right = mid - 1;
                } else if (count == h) {
                    right = mid - 1;
                }
            }
            return left;
        }
    };

    void test() {
        vector<int> piles = {30,11,23,4,20};
        cout << Solution().minEatingSpeed(piles, 6) << endl;
    }
}

#endif //LEETCODE875_H
