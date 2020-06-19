/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // 核心思想：S拆分S1和S2组成，T由T1和T2组成，若要T为S的扰乱字符串，则
  //          存在关系(S1==T1 && S2==T2) || （S1==T2 && S2==T1）
  //关于拆分: 每个位置都可能作为拆分点，题目要求只要一个拆分点能够满足要求即可

  // 递归方式解决
  bool isScramble(string s1, string s2) {
    // 最直观的长度和相等判断
    if (s1.size() != s2.size()) return false;
    if (s1 == s2) return true;

    // 互为扰乱字符串的基础是 s1和s2中字母只是位次不同
    vector<int> dict(26, 0);
    for (auto i = 0; i < s1.size(); ++i) {
      dict[s1[i] - 'a']++;
      dict[s2[i] - 'a']--;
    }
    for (auto count : dict) {
      if (count != 0) return false;
    }
    // 针对s1和s2需要递归判断是否构成扰乱字符串 按照所有位置都进行拆分
    auto total_length = s1.size();
    for (auto len = 1; len < total_length; ++len) {
      // (S1==T1 && S2==T2) || （S1==T2 && S2==T1）
      if ((isScramble(s1.substr(0, len), s2.substr(0, len)) &&
           isScramble(s1.substr(len), s2.substr(len))) ||
          (isScramble(s1.substr(0, len), s2.substr(total_length - len)) &&
           isScramble(s1.substr(len), s2.substr(0, total_length - len)))) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
