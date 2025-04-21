//
// Created by Oliver on 2025/4/21.
//

#ifndef LEETCODE438_H
#define LEETCODE438_H

#include "../util.h"

namespace LeetCode438 {
    class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            unordered_map<char, int> need;
            for (auto c : p) {
                need[c]++;
            }
            int left = 0, right = 0, count = 0;
            unordered_map<char, int> window;
            vector<int> result;
            while (right < s.size()) {
                char c = s[right];
                right++;
                if (need.count(c)) {
                    window[c]++;
                    if (window[c] == need[c]) {
                        count++;
                    }
                }
                while (right - left >= p.size()) {
                    if (count == need.size()) {
                        result.push_back(left);
                    }
                    char c = s[left];
                    left++;
                    if (need.count(c)) {
                        if (window[c] == need[c]) {
                            count--;
                        }
                        window[c]--;
                    }
                }
            }
            return result;
        }
    };

    void test() {
        string s = "abab", p = "ab";
        vector<int> ans = Solution().findAnagrams(s, p);
        print(ans);
    }
}

#endif //LEETCODE438_H
