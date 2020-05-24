/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  // 最长回文 动态规划：P(i,j)表示s中i-j之间的字符是否为回文
  // 取决于去除两边的字符后的串是回文，且两边字符相等，转移状态为:
  // P(i,j) = P(i+1, j-1) && s(i) == s(j)
  string longestPalindrome(string s) {
    if (s.empty()) return s;

    string result = "";
    size_t count = s.size();
    vector<vector<int>> dp(count, vector<int>(count));
    // l为回文串的长度(认为至少一个字符)
    for (size_t l = 0; l < s.size(); ++l) {
      // i字符串起始位置 注意终止的位置
      for (size_t i = 0; i + l < s.size(); ++i) {
        size_t j = i + l;  // 终止的位置
        if (l == 0) {
          // 单个字符始终为回文字串
          dp[i][j] = 1;
        } else if (l == 1) {
          // 两个字符是否回文取决于是否相等
          dp[i][j] = (s[i] == s[j]) ? 1 : 0;
        } else {
          // 两个以上的则由去除首位的子串是否回文和首位字符是否相同决定
          dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
        }

        // 最终结果
        if (dp[i][j] && l + 1 > result.size()) {
          result = s.substr(i, l + 1);
        }
      }
    }
    return result;
  }
};
// @lc code=end
