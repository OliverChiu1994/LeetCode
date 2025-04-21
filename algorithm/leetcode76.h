//
// Created by Oliver on 2025/4/21.
//

#ifndef LEETCODE76_H
#define LEETCODE76_H

#include "../util.h"

namespace LeetCode76 {
    class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char, int> need;
            for (char c : t) {
                need[c]++;
            }
            int left = 0, right = 0;
            int start = 0, len = INT_MAX;
            unordered_map<char, int> current;
            int count = 0;
            while (right < s.size()) {
                char c = s[right];
                if (need.find(c) != need.end()) {
                    current[c]++;
                    if (current[c] == need[c]) {
                        count++;
                    }
                }
                right++;
                while (count == need.size()) {
                    int curLen = right - left;
                    if (curLen < len) {
                        len = curLen;
                        start = left;
                    }
                    char deleteChar = s[left];
                    if (current.find(deleteChar) != current.end()) {
                        current[deleteChar]--;
                        if (current[deleteChar] < need[deleteChar]) {
                            count--;
                        }
                    }
                    left++;
                }
            }
            if (len < INT_MAX) {
                return s.substr(start, len);
            }
            return "";
        }
    };

    void test() {
        string s = "a";
        string t = "aa";
        string res = Solution().minWindow(s, t);
        cout << res << endl;
    }
}

#endif //LEETCODE76_H
