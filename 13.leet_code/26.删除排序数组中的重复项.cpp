/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    // 数组是有序的 因此相等的元素必定相邻
    if (nums.empty() || nums.size() == 1) {
      return nums.size();
    }
    size_t slow = 0;
    for (size_t quick = 1; quick < nums.size(); ++quick) {
      if (nums[slow] != nums[quick]) {
        slow++;
        nums[slow] = nums[quick];
      }
    }
    return slow + 1;
  }
};
// @lc code=end
