/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    // 优化 只使用一个vec即可
    if (s.size() != t.size()) return false;
    vector<int> vec(26, 0);
    for (auto i = 0; i < s.size(); ++i) {
      vec[s[i] - 'a']++;
      vec[t[i] - 'a']--;
    }
    for (auto i = 0; i < vec.size(); ++i) {
      if (vec[i] != 0) return false;
    }
    return true;
  }

 private:
  bool isAnagramPrivate(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> s_vec(26, 0);
    vector<int> t_vec(26, 0);
    for (auto ch : s) {
      s_vec[ch - 'a']++;
    }
    for (auto ch : t) {
      t_vec[ch - 'a']++;
    }
    for (auto i = 0; i < s_vec.size(); ++i) {
      if (s_vec[i] != t_vec[i]) return false;
    }
    return true;
  }
};
// @lc code=end
