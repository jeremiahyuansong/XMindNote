/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    // 采用循环的方式更新头节点
    //     while (head && head->val == val) {
    //       head = head->next;
    //     }
    //     ListNode* pi = head;
    //     while (pi && pi->next) {
    //       if (pi->next->val == val) {
    //         pi->next = pi->next->next;
    //       } else {
    //         pi = pi->next;
    //       }
    //     }
    //     return head;

    // 采用新设置一个无意义的头节点方式(哨兵节点)
    ListNode* new_head = new ListNode(-1);
    new_head->next = head;
    ListNode* iter = new_head;
    while (iter && iter->next) {
      if (iter->next->val == val) {
        iter->next = iter->next->next;
      } else {
        iter = iter->next;
      }
    }
    ListNode* result = new_head->next;
    delete new_head;
    return result;
  }
};
// @lc code=end
