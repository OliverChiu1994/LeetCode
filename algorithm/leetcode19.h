//
// Created by Oliver on 2025/4/9.
//

#ifndef LEETCODE19_H
#define LEETCODE19_H

#include "../util.h"

namespace LeetCode19 {
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode *slow = dummy, *fast = dummy;
            for (int i = 0; i < n; i++) {
                if (fast->next == nullptr) {
                    return dummy->next;
                }
                fast = fast->next;
            }
            while (fast->next != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
            return dummy->next;
        }
    };
}

#endif //LEETCODE19_H
