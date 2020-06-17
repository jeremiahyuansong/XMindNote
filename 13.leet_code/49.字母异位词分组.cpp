/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result{};
    unordered_map<string, vector<string>> dic{};

    // 对元素sort之后插入到hash表中
    for (auto i = 0; i < strs.size(); ++i) {
      string sort_result = strs[i];
      sort(sort_result.begin(), sort_result.end());
      dic[sort_result].emplace_back(strs[i]);
    }

    // 先分配空间不构造
    result.reserve(dic.size());
    size_t index = 0;
    for (auto iter = dic.begin(); iter != dic.end(); ++iter, ++index) {
      result.emplace_back();
      result[result.size() - 1] = std::move(iter->second);
    }
    return result;
  }
};
// @lc code=end
