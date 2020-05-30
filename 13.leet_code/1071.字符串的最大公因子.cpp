/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) {
      return "";
    }

    return str1.substr(0, gcd(str1.length(), str2.length()));
  }

 private:
  // 辗转相除法求最大公约数
  int gcd(int num1, int num2) {
    return num2 == 0 ? num1 : gcd(num2, num1 % num2);
  }
};
// @lc code=end
