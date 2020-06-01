/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
// 暴力方法至少要写出来吧(测试用例有超时的)
#if 0
    if (nums.empty()) return;
    int target = k % nums.size();
    int last = 0, temp = 0;
    for (size_t i = 0; i < target; ++i) {
      last = nums[nums.size() - 1];
      // 每次只移动一位
      for (size_t j = 0; j < nums.size(); ++j) {
        temp = nums[j];
        nums[j] = last;
        last = temp;
      }
    }
#endif

// 尝试一波用一个新的数组(空间复杂度为o(n))
#if 0
    if (nums.empty()) return;
    vector<int> new_nums(
        nums.size(),
        0);  // 每次记不住哪个代表数量 其实就是口语：初始化为多少个0
    int length = nums.size();
    for (size_t i = 0; i < length; ++i) {
      new_nums[(i + k) % length] = nums[i];
    }
    for (size_t i = 0; i < length; ++i) {
      nums[i] = new_nums[i];
    }
#endif

    // 高端方法 offset =  k % size 个元素会被移动到头部
    // 第一次全部反转 1 2 3 4 5 6 7 -> 7 6 5 4 3 2 1
    // 前offset个反转 7 6 5 4 3 2 1 -> 5 6 7 4 3 2 1
    // 后size-offset个反转 5 6 7 4 3 2 1 -> 5 6 7 1 2 3 4
    if (nums.empty()) return;
    int length = nums.size();
    int offset = k % length;
    Reserver(nums, 0, length - 1);
    Reserver(nums, 0, offset - 1);
    Reserver(nums, offset, length - 1);
  }

 private:
  void Reserver(vector<int>& nums, int start, int end) {
    while (start < end) {
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
      ++start;
      --end;
    }
  }
};
// @lc code=end
