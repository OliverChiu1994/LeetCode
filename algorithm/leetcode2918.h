//
// Created by Oliver on 2025/5/10.
//

#ifndef LEETCODE2918_H
#define LEETCODE2918_H

#include "../util.h"

namespace LeetCode2918 {
    class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            long long sum1 = 0;
            long long sum2 = 0;
            for (int i = 0; i < nums1.size(); i++) {
                sum1 += nums1[i];
                sum2 += nums1[i];
                if (nums1[i] == 0) {
                    sum1++;
                }
            }

            long long sum3 = 0;
            long long sum4 = 0;
            for (int i = 0; i < nums2.size(); i++) {
                sum3 += nums2[i];
                sum4 += nums2[i];
                if (nums2[i] == 0) {
                    sum3++;
                }
            }

            long long min1 = max(sum1, sum2);
            long long max1 = sum1 == sum2 ? min1 : 1e12;
            long long min2 = max(sum3, sum4);
            long long max2 = sum3 == sum4 ? min2 : 1e12;

            if ((max1 == min1 && max1 < min2) || (max2 == min2 && max2 < min1)) {
                return -1;
            }
            return max(min1, min2);
        }
    };

    void test() {
        vector<int> nums1 = { 2,0,2,0 };
        vector<int> nums2 = { 1,4 };
        cout <<Solution().minSum(nums1, nums2) << endl;
    }
}

#endif //LEETCODE2918_H
