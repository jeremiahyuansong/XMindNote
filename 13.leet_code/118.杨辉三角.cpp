/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    result.resize(numRows);
    for (size_t i = 0; i < numRows; ++i) {
      auto &line = result[i];  // 这里的引用容易忘记
      line.resize(i + 1);
      for (size_t line_iter = 0; line_iter != i + 1; ++line_iter) {
        if (line_iter == 0 || line_iter == i) {
          line[line_iter] = 1;
        } else {
          line[line_iter] = result[i - 1][line_iter - 1] + result[i - 1][line_iter];
        }
      }
    }
    return result;
  }
};
// @lc code=end
