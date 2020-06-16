/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
 public:
  /**
   * 题目描述的不是很清晰 没有说是后面和前面的依次进行替换
   * */
  string reverseVowels(string s) {
    if (s.empty()) return "";
    size_t left = 0, right = s.size() - 1;
    string target = "aeiouAEIOU";
    while (left < right) {
      while (target.find(s[left]) == string::npos && left < right) {
        left++;
      }

      while (target.find(s[right]) == string::npos && left < right) {
        right--;
      }
      if (left < right) swap(s[right--], s[left++]);
    }
    return s;
  }
};
// @lc code=end
