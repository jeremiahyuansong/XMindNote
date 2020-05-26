/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
 public:
  void reverseString(vector<char>& s) {
    char temp;
    size_t length = s.size();
    for (size_t i = 0; i < length / 2; ++i) {
      temp = s[i];
      s[i] = s[length - i - 1];
      s[length - i - 1] = temp;
    }
  }
};
// @lc code=end
