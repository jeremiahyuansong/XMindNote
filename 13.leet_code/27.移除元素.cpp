/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) {
      return 0;
    }
    size_t slow = 0;
    for (size_t quick = 0; quick < nums.size(); ++quick) {
      if (nums[quick] != val) {
        nums[slow] = nums[quick];
        ++slow;
      }
    }
    return slow;
  }
};
// @lc code=end
