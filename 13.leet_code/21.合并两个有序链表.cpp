/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy_node = new ListNode(-1);
    ListNode* cur_node = dummy_node;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        cur_node->next = l1;
        l1 = l1->next;
      } else {
        cur_node->next = l2;
        l2 = l2->next;
      }
      cur_node = cur_node->next;
    }
    if (l1) cur_node->next = l1;
    if (l2) cur_node->next = l2;
    ListNode* result = dummy_node->next;
    delete dummy_node;
    return result;
  }
};
// @lc code=end
