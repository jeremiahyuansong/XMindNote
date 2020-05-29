/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  char findTheDifference(string s, string t) {
    char result = 'a';
    vector<int> count_s(26, 0);
    vector<int> count_t(26, 0);
    for (auto ch : s) {
      count_s[ch - 'a']++;
    }
    for (auto ch : t) {
      count_t[ch - 'a']++;
    }
    for (size_t i = 0; i < 26; ++i) {
      if (count_s[i] != count_t[i]) {
        result = 'a' + i;
        break;
      }
    }
    return result;
  }
};
// @lc code=end
