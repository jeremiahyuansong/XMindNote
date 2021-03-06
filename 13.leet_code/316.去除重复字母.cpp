/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母 保证返回的字符串字典序最小
 */

// @lc code=start

#include <algorithm>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  string removeDuplicateLettersV1(string s) {
    if (s.empty()) return "";
    vector<size_t> count(26, 0);
    stack<char> res_stack{};
    unordered_set<char> res_set{};  // 判断当前栈中存在的元素 重复插入的时候跳过
    for (auto ch : s) {
      count[ch - 'a']++;
    }
    for (size_t i = 0; i < s.size(); ++i) {
      count[s[i] - 'a']--;
      if (res_set.count(s[i]) != 0) continue;
      // 单调栈状态更新：非空、栈顶元素大于当前遍历s[i]、后续还有该字母
      while (!res_stack.empty() && res_stack.top() > s[i] && count[res_stack.top() - 'a'] > 0) {
        res_set.erase(res_stack.top());
        res_stack.pop();
      }
      res_stack.push(s[i]);
      res_set.emplace(s[i]);
    }
    string result = "";
    while (res_stack.size()) {
      result += res_stack.top();
      res_stack.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }

 public:
  /**
   * 优化版本：string代替调用栈、bool数组代替hash表
   * */
  string removeDuplicateLetters(string s) {
    if (s.empty()) return "";
    string result = "";
    vector<bool> visit(26, false);  // 判定res结果中是否已经存在当前字符
    vector<size_t> count(26, 0);    // 判定后续是否还有该字符
    for (auto ch : s) {
      count[ch - 'a']++;
    }
    for (size_t i = 0; i < s.size(); ++i) {
      count[s[i] - 'a']--;
      if (visit[s[i] - 'a']) continue;
      while (!result.empty() && result.back() > s[i] && count[result.back() - 'a'] > 0) {
        visit[result.back() - 'a'] = false;
        result.erase(result.size() - 1, 1);
      }
      result += s[i];
      visit[s[i] - 'a'] = true;
    }
    return result;
  }
};
// @lc code=end
