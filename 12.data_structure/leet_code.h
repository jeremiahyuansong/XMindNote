/***************************************************************************
 * @file leet_code.cpp
 * @author jeremiahyuansong
 * @date 2020/5/10
 * @brief 做一些leetCode题目
 ***************************************************************************/

#include <iostream>
#include <string>

class Solution {
 public:
  Solution() = default;

  ~Solution() = default;

  /*
   * @brief 给一个一定长度n的字符串s, 求其中k（k<=n）个字符的组合
   *        "ab"和"ba"算同一种 字符串内无重复字符
   */
  void DoStringCombination(const std::string& src, const size_t& target_n) {
    if (src.empty() || target_n <= 0) {
      std::cout << "input error" << std::endl;
      return;
    }
    std::string res("");
    // 这个地方current_n传1 是为了后面递归中current_n方便和target_n判断
    StringCombinationImp(src, target_n, 1, 0, res);
  }

 private:
  // abcd n = 2
  /*
   * a ab
   *   ac
   *   ad
   * b
   *   bc
   *   bd
   * c
   *   cd
   * d null
   */

  // abcd n = 3
  /*
      a ab abc
           abd
        ac acd
        ad null
      b bc bcd
        bd null
      c cd null
      d null
   */
  /// 使用递归实现
  void StringCombinationImp(const std::string& src, const int target_n, size_t current_n,
                            size_t start_index, std::string res) {
    // 保存下当前的正在处理的字串 后面用于还原 eg: ab组合后,
    // 重新回到a,继续后面ac
    std::string s = res;
    for (size_t i = start_index; i < src.length() - (target_n - current_n); ++i) {
      if (current_n <= target_n) {
        res += src.substr(i, 1);
        StringCombinationImp(src, target_n, current_n + 1, i + 1, res);
        if (current_n == target_n) {
          std::cout << res << std::endl;
        }
      } else {
        return;
      }
      res = s;
    }
  }
};
