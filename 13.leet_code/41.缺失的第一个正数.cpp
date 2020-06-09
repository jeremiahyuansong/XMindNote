/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
    int length = nums.size();

    for (size_t i = 0; i < length; ++i) {
      // 确认三个状态
      // 正数
      // 小于lenth+1(极限情况就是length=4 正好1 2 3 4个数字都存在 这时缺失的数字就是length+1)
      // 替换前后的数字不相等
      while (nums[i] > 0 && nums[i] < length + 1 && nums[nums[i] - 1] != nums[i]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (size_t i = 0; i < length; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    //正好各司其位 这时缺失的最小整数就是length + 1
    return length + 1;
  }
};
// @lc code=end
