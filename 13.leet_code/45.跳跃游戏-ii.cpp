/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  // 边界方法:次数的更新是通过到达边界的时候在条件里进行更新
  // 2 3 1 1 4
  // i  maxpos  end  step
  // 0    2      2    1
  // 1    4      2    1
  // 2    4      4    2
  // 3    4      4    2
  // 4    4      4    2
  int jump(vector<int> &nums) {
    size_t maxpos = 0, end = 0, step = 0;
    // 结束的条件是到达前一个元素
    for (size_t i = 0; i < nums.size() - 1; ++i) {
      if (maxpos >= i) {
        // 当前位置在能达到的范围内
        maxpos = std::max(maxpos, i + nums[i]);
        if (end == i) {
          // 到达约定的边界 更新step的次数
          end = maxpos;
          ++step;
        }
      }
    }
    return step;
  }

 private:
  int jump_private(vector<int> &nums) {
    // 贪心算法：在每轮可以做出的决策中 选择最优的决策
    if (nums.size() == 1) {
      return 0;
    }
    auto length = nums.size();
    auto cur_pos = 0;
    auto jump_count = 0;
    while (cur_pos + nums[cur_pos] < length - 1) {  // 状态:当前位置跳不到最后节点
      auto end_index = cur_pos + nums[cur_pos];
      auto most_far_index = 0;  // 每一轮中最远jump的距离初始化
      // 注意边界 这里需要更新的i应该为[cur_pos+1, cur_pos + nums[cur_pos]]
      for (auto i = cur_pos + 1; i <= end_index; ++i) {
        if (i + nums[i] > most_far_index) {
          // 更新当前轮决定使用的cur_pos和最远的位置
          cur_pos = i;
          most_far_index = i + nums[i];
        }
      }
      // 一轮结束后 跳一次
      jump_count++;
    }

    return jump_count + 1;
  }
};
// @lc code=end
