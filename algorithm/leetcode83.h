//
// Created by Oliver on 2025/4/14.
//

#ifndef LEETCODE83_H
#define LEETCODE83_H

#include "../util.h"

namespace LeetCode83 {
    class Solution {
    public:
        // 双指针
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == nullptr) {
                return head;
            }
            ListNode* slow = head, *fast = head;
            while (fast) {
                if (fast->val != slow->val) {
                    slow->next = fast;
                    slow = slow->next;
                }
                fast = fast->next;
            }
            slow->next = nullptr;
            return head;
        }
    };
}

#endif //LEETCODE83_H
