/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start

#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    size_t row_size = grid.size();
    size_t cloumn_size = grid[0].size();
    int last_perfect_orange = 0;
    int result = -1;

    auto need_change = [&](const int& row_index, const int& col_index) {
      // 行列超出范围限制 无需更新
      if (row_index < 0 || row_index >= row_size) {
        return false;
      }

      if (col_index < 0 || col_index >= cloumn_size) {
        return false;
      }

      // 位置上是好橘子 需要更新
      if (grid[row_index][col_index] == 1) {
        return true;
      }

      return false;
    };

    // 经过的极限分钟数 为每分钟只有一个橘子变坏
    for (size_t i = 0; i < row_size * cloumn_size; ++i) {
      vector<pair<int, int>> bad_index;  //记录下本轮中腐烂橘子的index位置
      last_perfect_orange = 0;
      for (size_t row = 0; row < row_size; ++row) {
        for (size_t column = 0; column < cloumn_size; ++column) {
          if (grid[row][column] == 2) {
            // 记录下待更改的行和列位置
            bad_index.push_back({row, column});
          } else if (grid[row][column] == 1) {
            last_perfect_orange++;
          }
        }
      }
      int new_perfect_orange = last_perfect_orange;
      for (auto row_col : bad_index) {
        // 左
        if (need_change(row_col.first, row_col.second - 1)) {
          grid[row_col.first][row_col.second - 1] = 2;
          new_perfect_orange--;
        }
        // 右
        if (need_change(row_col.first, row_col.second + 1)) {
          grid[row_col.first][row_col.second + 1] = 2;
          new_perfect_orange--;
        }

        // 上
        if (need_change(row_col.first - 1, row_col.second)) {
          grid[row_col.first - 1][row_col.second] = 2;
          new_perfect_orange--;
        }

        // 下
        if (need_change(row_col.first + 1, row_col.second)) {
          grid[row_col.first + 1][row_col.second] = 2;
          new_perfect_orange--;
        }
      }

      if (last_perfect_orange == 0) {
        result = i;
        break;
      } else if (new_perfect_orange == last_perfect_orange) {
        result = -1;
        break;
      }
    }
    return result;
  }
};
// @lc code=end
