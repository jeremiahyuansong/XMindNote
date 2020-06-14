/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  // Sunday算法 看了官网实现一下，还挺有意思
  // "核心思想"：   通过比较haystack的[idx,idx + len(needle))子串和needle是否相等来寻找
  // "偏移表"：     对于needle模板会建立一个偏移表，存放的是needle中每个字符出现的最右位置+1
  //              这个偏移表后面会用来更新idx起始位置
  // "idx更新逻辑"：传统方法就是依次递增idx，sunday算法对这里进行了优化
  //    a、下一个待匹配位字符haystack[idx+len(needle)+1]不在偏移表中,idx = idx + len(needle) +1
  //       直观理解就是：checkthis和this在[0,4)匹配失败，查看下一个k不在偏移表，直接跳到idx+len(needle)+1
  //    b、下一个待匹配位字符haystack[idx+len(needle)+1]在偏移表中， idx = idx + table['字符']
  //        直观理解就是：因为上一轮不匹配，在所有包含了下一个字符的子串中idx需要偏移的最短的距离
  // 整体来说，优化的点在于利用了上一次不匹配的结果信息来处理内容
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;

    auto hay_len = haystack.size(), needle_len = needle.size();

    if (hay_len < needle_len) return -1;

    unordered_map<char, size_t> offset_table{};

    for (auto i = 0; i < needle.size(); ++i) {
      offset_table[needle[i]] = needle_len - i;  // 偏移距离为到末尾的元素距离+1
    }

    auto idx = 0;
    while (idx + needle_len - 1 < hay_len) {
      if (haystack.substr(idx, needle_len) == needle) {
        return idx;
      }
      // 不相等的情况更新idx
      auto next_index = std::min(hay_len, idx + needle_len);
      auto find_iter = offset_table.find(haystack[next_index]);
      if (find_iter != offset_table.end()) {
        // 下一位字符出现在偏移表中
        idx += find_iter->second;
      } else {
        // 下一位字符未出现在偏移表
        idx += (needle_len + 1);
      }
    }
    return -1;
  }

 private:
  int strStrPrivate(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }

    size_t hay_len = haystack.size();
    size_t needle_len = needle.size();
    if (hay_len < needle_len) return -1;
    // 这题用窗口依次去判断窗口内的每一个元素的方式会出现超时
    // 直接使用了substr
    for (size_t idx = 0; idx < hay_len - needle_len + 1; ++idx) {
      if (haystack.substr(idx, needle_len) == needle) {
        return idx;
      }
    }

    return -1;
  }
};
// @lc code=end
