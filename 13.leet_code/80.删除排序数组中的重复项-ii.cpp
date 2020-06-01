/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 3) {
      return nums.size();
    }
    size_t slow = 1;
    for (size_t quick = 2; quick < nums.size(); ++quick) {
      // 和之前的26题对比 他的保留两个重复项的状态是由和slow的前一个元素对比完成
      if (nums[quick] != nums[slow - 1]) {
        nums[++slow] = nums[quick];
      }
    }
    return slow + 1;
  }

 private:
  int removeDuplicatesError(vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) {
      return nums.size();
    }
    size_t slow = 0;
    size_t repeat_num = 1;  // 当前元素已经算一个
    // 我尼玛 这种一个每种情形对应去判断的思路 总是有case通不过
    for (size_t quick = 1; quick < nums.size(); ++quick) {
      // 相等
      if (nums[slow] == nums[quick]) {
        if (repeat_num < 2) {
          ++slow;
          repeat_num++;
        } else {
          repeat_num++;
        }
      } else {
        nums[++slow] = nums[quick];
        repeat_num = 1;
      }
    }
    return slow + 1;
  }
};
// @lc code=end
