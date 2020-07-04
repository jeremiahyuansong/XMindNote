// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem38.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    if (n < 1 || n > 30) return "";
    if (n == 1) return "1";
    string last_str = "1";
    string result_str = "";
    while (--n) {
      string cur_str = "";
      for (auto index = 0; index < last_str.size();) {
        auto last_ch = last_str[index];
        auto count = 0;
        while (index < last_str.size() && last_str[index] == last_ch) {
          ++index;
          ++count;
        }
        cur_str += (to_string(count) + last_ch);
      }
      last_str = cur_str;
      if (n == 1) {
        result_str = cur_str;
      }
    }
    return result_str;
  }
};
// @lc code=end
