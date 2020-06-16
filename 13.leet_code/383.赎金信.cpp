/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<uint32_t> ran_vec(26, 0);
    vector<uint32_t> mag_vec(26, 0);
    for (auto ra : ransomNote) {
      ran_vec[ra - 'a']++;
    }
    for (auto ma : magazine) {
      mag_vec[ma - 'a']++;
    }

    for (auto i = 0; i < ran_vec.size(); ++i) {
      if (ran_vec[i] > mag_vec[i]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
