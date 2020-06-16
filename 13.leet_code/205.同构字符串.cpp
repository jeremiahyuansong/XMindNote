/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, size_t> s_count{}, t_count{};
    // 这种方法逻辑上没有解决同一个字符的数量问题吧
    for (size_t i = 0; i < s.size(); ++i) {
      s_count[s[i]] = i;
      t_count[t[i]] = i;
    }

    for (size_t i = 0; i < s.size(); ++i) {
      if (s_count[s[i]] != t_count[t[i]]) return false;
    }
    return true;
  }
};
// @lc code=end
