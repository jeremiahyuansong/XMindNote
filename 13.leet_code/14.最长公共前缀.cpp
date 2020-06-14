/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // 利用字典序的排序来找公共匹配(验证下来这玩意只是代码短一些 实际效率不如暴力法)
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    auto length = strs.size();
    sort(strs.begin(), strs.end());
    for (auto i = 0; i < std::min(strs[0].size(), strs[length - 1].size()); ++i) {
      if (strs[0][i] != strs[length - 1][i]) return strs[0].substr(0, i);
    }
    return strs[0];
  }

 private:
  // 通过最短的子串去一一和其他串比较每一位的相等情况
  string longestCommonPrefixPrivate(vector<string> &strs) {
    if (strs.empty()) return "";
    size_t min_index = 0, min_length = strs[0].size();
    // find shortest string
    for (auto i = 0; i < strs.size(); ++i) {
      if (strs[i].size() < min_length) {
        min_index = i;
        min_length = strs[i].size();
      }
    }

    // judge common prefix through the shortest string
    auto i = 0;
    for (; i < min_length; ++i) {
      auto target = strs[min_index][i];
      auto find_differ = false;
      for (auto j = 0; j < strs.size(); ++j) {
        if (strs[j][i] != target) {
          find_differ = true;
          break;
        }
      }
      if (find_differ) break;
    }

    return i == 0 ? "" : strs[min_index].substr(0, i);
  }
};
// @lc code=end
