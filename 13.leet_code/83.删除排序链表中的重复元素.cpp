/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* pi = head;
    while (pi && pi->next) {
      // 只需要判定相邻节点的重复问题
      if (pi->val == pi->next->val) {
        // 有重复的时候只需要指向下一节点的下一节点  不需要更新pi
        pi->next = pi->next->next;
      } else {
        pi = pi->next;
      }
    }
    return head;
  }
};
// @lc code=end
