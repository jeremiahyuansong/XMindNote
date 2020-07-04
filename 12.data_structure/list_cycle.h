/**
 * @file list_cycle.h
 * @author yuansong
 * @date 2020/7/3
 * @brief 单链表的环问题测试
 */

#ifndef DESIGN_PATTERN_12_DATA_STRUCTURE_LIST_CYCLE_H_
#define DESIGN_PATTERN_12_DATA_STRUCTURE_LIST_CYCLE_H_

class SolutionList {
 public:
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
  };

  /**
   * 递归输出链表
   * @param node
   */
  static void OutListNode(ListNode* node) {
    if (!node) {
      return;
    }
    std::cout << node->val << std::endl;
    if (node->next) {
      OutListNode(node->next);
    }
  }

  /**
   * 检测单链表是否含环
   * @param head
   * @return
   */
  bool HasCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }

  /**
   * 检测单链表环的入口位置
   * @param head
   * @return
   */
  ListNode* DetectCycle(ListNode* head) {
    // same as HasCycle function
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        break;
      }
    }
    // list does not have cycle
    if (fast != slow) return nullptr;
    // list has cycle
    slow = head;
    while (slow && fast) {
      slow = slow->next;
      fast = fast->next;
      if (fast == slow) {
        return fast;
      }
    }
    return nullptr;
  }

  /**
   * 删除链表末尾第n个节点
   * @param head
   * @param n
   * @return
   */
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 一遍 遍历知道元素的个数
    size_t num = 0;
    // 删除的可能是头元素 需要一个桩
    ListNode* new_head = new ListNode(-1);
    new_head->next = head;
    ListNode* iter = new_head;
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
};

#endif  // DESIGN_PATTERN_12_DATA_STRUCTURE_LIST_CYCLE_H_
