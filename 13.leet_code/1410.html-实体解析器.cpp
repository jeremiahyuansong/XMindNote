/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
 public:
  string entityParser(string text) {
    text = ReplaceAll(text, "&quot;", "\"");
    text = ReplaceAll(text, "&apos;", "'");
    text = ReplaceAll(text, "&frasl;", "/");
    text = ReplaceAll(text, "&gt;", ">");
    text = ReplaceAll(text, "&lt;", "<");
    return ReplaceAll(text, "&amp;", "&");
  }

 private:
  string ReplaceAll(const string& text, const string& src, const string& dst) {
    string result = text;
    size_t start_index = 0;
    while ((start_index = result.find(src, start_index)) != string::npos) {
      // replace 使用大部分限定开始的位置、替换的个数，目标字符串
      // 其他替换为目标字符串某一部分的暂时不用去记
      result.replace(start_index, src.size(), dst);
      start_index += dst.size();
    }
    return result;
  }
};
// @lc code=end
