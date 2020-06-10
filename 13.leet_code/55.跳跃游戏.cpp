/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int> &nums) {
    // 编码简单 思路复杂系列
    // 如果一个位置i可以到达，那么后面nums[i]个格子都可以作为起跳点
    // 尝试每个起跳点的过程中 不断更新最远的距离 若能够达到n-1则返回true
    // 否则最后返回false
    auto length = nums.size();
    auto most_far_index = 0;
    for (auto i = 0; i < length; ++i) {
      if (i <= most_far_index) {  // 当前位置在最远能跳到的位置范围内
        most_far_index = std::max(most_far_index, i + nums[i]);
        if (most_far_index >= length - 1) {
          // 能够跳到最后
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end
