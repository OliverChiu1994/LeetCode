//
// Created by Oliver on 2025/4/8.
//

#ifndef LEETCODE142_H
#define LEETCODE142_H

#include "../util.h"

namespace LeetCode142 {
    class Solution {
    public:
        //快慢指针
        ListNode *detectCycle(ListNode *head) {
            ListNode *slow = head, *fast = head;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    break;
                }
            }
            if (!fast || !fast->next) {
                return nullptr;
            }
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    };
}

#endif //LEETCODE142_H
