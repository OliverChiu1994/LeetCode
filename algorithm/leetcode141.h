//
// Created by Oliver on 2025/4/8.
//

#ifndef LEETCODE141_H
#define LEETCODE141_H

#include "../util.h"

namespace LeetCode141 {
    class Solution {
    public:
        // 快慢指针
        bool hasCycle(ListNode *head) {
            ListNode *slow = head, *fast = head;
            while (fast && fast->next) {
                if (slow == fast) {
                    return true;
                }
                slow = slow->next;
                fast = fast->next->next;
            }
            return false;
        }
    };
}

#endif //LEETCODE141_H
