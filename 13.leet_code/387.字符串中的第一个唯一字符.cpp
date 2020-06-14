/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    vector<uint32_t> ch_count(26, 0);

    for (auto ch : s) {
      ch_count[ch - 'a']++;
    }

    for (auto i = 0; i < s.size(); ++i) {
      if (ch_count[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end
