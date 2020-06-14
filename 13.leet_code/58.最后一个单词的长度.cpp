/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    if (s.empty()) return 0;
    auto find_iter = s.find_last_of(' ');
    if (find_iter == string::npos) {
      return static_cast<int>(s.size());
    }
    // 最后一个是空格的情况 利用递归处理
    if (find_iter == (s.size() - 1)) {
      return lengthOfLastWord(s.substr(0, s.size() - 1));
    }
    return static_cast<int>(s.size() - 1 - find_iter);
  }
};
// @lc code=end
