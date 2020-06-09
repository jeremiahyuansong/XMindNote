/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // 遍历从gas的每个节点出发最后能否返回原点的情况
    // 状态判断：当前剩余的汽油 和 当前所在的加油站是否是出发的加油站
    size_t length = gas.size();
    int result = -1;
    for (size_t start_gas = 0; start_gas < length; ++start_gas) {
      // 从start开始出发的情况
      int left = gas[start_gas];  // 初始汽油
      int count = length;         // 计数移动的次数 减为0证明回到原点
      size_t current_gas = start_gas;
      while (left >= cost[current_gas] && count > 0) {
        left -= cost[current_gas];  // 耗费的汽油
        current_gas = (current_gas + 1) % length;
        left += gas[current_gas];  // 新补充的汽油
        count--;
      }
      if (count == 0) {
        // 回到原点
        result = start_gas;
        break;
      }
    }
    return result;
  }
};
// @lc code=end
