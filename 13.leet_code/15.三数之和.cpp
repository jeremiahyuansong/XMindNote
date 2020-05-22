/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSumUnvaliable(vector<int>& nums) {
    // 暴力解法
    vector<vector<int>> result;
    unordered_set<string> remove_dup;
    for (int i = 0; i < nums.size() - 2; ++i) {
      int target_two = 0 - nums[i];
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        int target_one = target_two - nums[j];
        for (int k = j + 1; k < nums.size(); ++k) {
          if (nums[k] == target_one) {
            string dup =
                to_string(std::min(std::min(nums[i], nums[j]), nums[k])) +
                to_string(std::max(std::max(nums[i], nums[j]), nums[k]));

            if (remove_dup.count(dup) != 0) {
              continue;
            }
            remove_dup.insert(dup);
            result.push_back({nums[i], nums[j], nums[k]});
          }
        }
      }
    }
    return result;
  }

  // 排序后使用双指针L和R
  // 因为排序过 所以有这么几个特性：
  // (假设i为当前元素,得L = i + 1, R = lenght -1）
  // 1、nums[i]>0的话肯定不满足 三数凑0 2、nums[i] == nums[i-1]的话
  // 会造成重复 continue 3、nums[i] + nums[L] + nums[R] > 0 证明总体偏大 R--
  // 4、nums[i] + nums[L] + nums[R] < 0 证明总体偏小 L++
  // 5、nums[i] + nums[L] + nums[R] == 0 满足条件 push 同时判断nums[L] 和
  // nums[L+1]; nums[R] 和nums[R-1]是否相等 去除重复
  // 6、L与R相遇 重新开启新一轮 即i++
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result = {};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) continue;
      if (i != 0 && (nums[i] == nums[i - 1])) continue;
      int L = i + 1;
      int R = nums.size() - 1;
      while (L < R) {
        int ret = nums[i] + nums[L] + nums[R];
        if (ret == 0) {
          result.push_back({nums[i], nums[L], nums[R]});
          while (L < R && nums[L] == nums[L + 1]) L++;
          while (L < R && nums[R] == nums[R - 1]) R--;
          L++;
          R--;
        } else if (ret > 0) {
          R--;
        } else {
          L++;
        }
      }
    }
    return result;
  }
};
// @lc code=end
