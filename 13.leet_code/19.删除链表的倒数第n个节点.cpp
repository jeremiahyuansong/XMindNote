/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
  // 两遍遍历的方法
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 删除的可能是头元素 需要一个桩
    ListNode* new_head = new ListNode(-1);
    new_head->next = head;
    ListNode* iter = new_head;
    // 第一遍 遍历获取元素的个数
    size_t num = 0;
    while (iter) {
      ++num;
      iter = iter->next;
    }
    iter = new_head;
    size_t target = num - n;
    size_t num_iter = 0;
    while (num_iter + 1 != target) {
      num_iter++;
      iter = iter->next;
    }
    iter->next = iter->next->next;
    ListNode* result = new_head->next;
    delete new_head;
    return result;
  }

  // 一遍遍历 利用快慢指针 两指针的间隔为n个元素
  ListNode* removeNthFromEndDoublePointer(ListNode* head, int n) {
    // 删除的可能是头元素 需要一个桩
    ListNode* new_head = new ListNode(-1);
    new_head->next = head;
    ListNode* slow = new_head;
    ListNode* quick = new_head;

    // 快指针和慢指针之间间隔n个元素
    for (size_t i = 0; i <= n; ++i) {
      quick = quick->next;
    }

    // 同时移动快慢指针
    while (quick) {
      quick = quick->next;
      slow = slow->next;
    }

    // 快指针到达尾部下一个元素的时候 慢指针的下一个元素即倒数第n个
    ListNode* del = slow->next;
    slow->next = slow->next->next;
    delete del;
    ListNode* result = new_head->next;
    delete new_head;
    return result;
  }
};
// @lc code=end
