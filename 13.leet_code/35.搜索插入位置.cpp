/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <algorithm>

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    // return SearchInsertImp(nums, target, 0, nums.size() - 1, "");
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= target) {
        return i;
      }
    }
    return nums.size();
  }

 private:
  int SearchInsertImp(vector<int>& nums, int target, int left, int right,
                      const string& flag) {
    if (left > right) {
      if (flag == "L")
        return nums[left] > target
                   ? std::max(0, left - 1)
                   : std::min(static_cast<int>(nums.size()), left + 1);
      if (flag == "R")
        return nums[right] > target
                   ? std::max(0, right - 1)
                   : std::min(static_cast<int>(nums.size()), right + 1);
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      // 右边的可能减为一个无效的 传入“L”表示使用左参数
      return SearchInsertImp(nums, target, left, mid - 1, "L");
    } else {
      // 左边的可能增加为一个无效的 传入"R"表示使用右参数
      return SearchInsertImp(nums, target, mid + 1, right, "R");
    }
  }
};
// @lc code=end
