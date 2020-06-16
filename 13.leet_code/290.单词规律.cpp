/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    vector<string> split_result{};
    split(str, " ", split_result);
    if (pattern.size() != split_result.size()) return false;
    unordered_map<char, string> pa2str{};
    unordered_map<string, char> str2pa{};
    for (auto i = 0; i < pattern.size(); ++i) {
      pa2str[pattern[i]] = split_result[i];
      str2pa[split_result[i]] = pattern[i];
    }
    for (auto i = 0; i < pattern.size(); ++i) {
      // 主要通过有没有映射关系被覆盖来判断
      if (pa2str[pattern[i]] != split_result[i] || str2pa[split_result[i]] != pattern[i])
        return false;
    }
    return true;
  }

 private:
  /**
   * @describe: 通用的分割实现
   * */
  void split(const string &source, const string &split, vector<string> &result) {
    string::size_type start, end;
    start = 0;
    end = source.find(split);
    while (end != string::npos) {
      result.push_back(source.substr(start, end - start));
      // 更新起始和终止的位置
      start = end + split.size();
      end = source.find(split, start);  // 这里的find从新的start位置开始查找
    }
    // 处理剩余的串
    if (start < source.size()) result.push_back(source.substr(start));
  }
};
// @lc code=end
