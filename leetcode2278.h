//
// Created by Oliver on 2025/3/31.
//

#ifndef LEETCODE278_H
#define LEETCODE278_H

#include <cmath>
#include <string>

using namespace std;

namespace LeetCode2278 {
class Solution {
public:
    static int percentageLetter(string s, char letter) {
        if (s.empty()) return 0;
        int count = 0;
        for (const auto &c : s) {
            if (c == letter) {
                count++;
            }
        }
        // auto rate = (float)count / s.size();
        // return floor(rate * 100);

        return floor((float)count * 100 / s.size());
    }
};
}

#endif //LEETCODE278_H
