// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem179.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    // 字典序不能解决3和30的问题
    vector<string> str_nums;
    bool all_zero = true;
    for (auto number : nums) {
      if (number) all_zero = false;
      str_nums.emplace_back(to_string(number));
    }
    if (all_zero) return "0";
    // 难点在于定义两个字符串的大小关系 如果a_b>b_a,则a>b
    sort(str_nums.begin(), str_nums.end(),
         [](const string& left, const string& right) { return left + right < right + left; });
    string result = "";
    for (auto iter = str_nums.rbegin(); iter != str_nums.rend(); ++iter) {
      result += (*iter);
    }
    return result;
  }
};
// @lc code=end
