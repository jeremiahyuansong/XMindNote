/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    vector<string> vec_result{};
    auto length = s.size();
    auto start = 0;
    // 提取所有的单词
    while (start < length) {
      if (s[start] == ' ') {
        start++;
        continue;
      }
      auto end = start;
      while (s[end] != ' ' && end < length) {
        end++;
      }
      vec_result.push_back(s.substr(start, end - start));
      start = end;
    }

    string result = "";
    for (auto iter = vec_result.rbegin(); iter < vec_result.rend(); ++iter) {
      result += *iter;
      if (iter != (--vec_result.rend())) result += " ";
    }
    return result;
  }
};
// @lc code=end
