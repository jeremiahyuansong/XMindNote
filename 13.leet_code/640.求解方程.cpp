/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
 public:
  string solveEquation(string equation) {
    if (equation.empty()) return "No solution";
    auto find_equal = equation.find_first_of('=');
    if (find_equal == string::npos) return "No sulution";
    // 提取等号左右两边的表达式
    string left_equation = equation.substr(0, find_equal);
    string right_equation = equation.substr(find_equal + 1);

    // 分别计算左右两边的x数量和数字的数量
    int l_x_count = 0, r_x_count = 0;
    int l_digital_count = 0, r_digital_count = 0;
    CountXAndDigital(left_equation, l_x_count, l_digital_count);
    CountXAndDigital(right_equation, r_x_count, r_digital_count);

    // 计算未知数x的值
    int x_count = l_x_count - r_x_count;
    int digital_count = r_digital_count - l_digital_count;
    if (x_count == 0 && digital_count == 0) {
      return "Infinite solutions";
    } else if (x_count == 0) {
      return "No solution";
    } else {
      return "x=" + to_string(digital_count / x_count);
    }
  }

 private:
  void CountXAndDigital(const string& input, int& x_count, int& digital_count) {
    if (input.empty()) return;
    string operation_input = input;

    int last_xishu = 1;
    while (operation_input.size()) {
      size_t index = 0;
      if (operation_input[index] == '+') {
        last_xishu = 1;
      } else if (operation_input[index] == '-') {
        last_xishu = -1;
      } else {
        while (index < operation_input.size()) {
          if (operation_input[index] == '+' || operation_input[index] == '-') {
            index--;  // 退回到上一个位置 方便最后更新operation_input
            break;
          }
          index++;
        }
        string str_x_or_digital = operation_input.substr(0, index + 1);
        auto find_x = str_x_or_digital.find_first_of('x');
        if (find_x != string::npos) {
          // 未知数
          if (find_x == 0) {
            x_count = x_count + last_xishu;
          } else {
            x_count =
                x_count + last_xishu * stoi(str_x_or_digital.substr(0, find_x));
          }
        } else {
          // 数字
          digital_count = digital_count + last_xishu * stoi(str_x_or_digital);
        }
      }
      if (index == operation_input.size()) break;  // 外层循环结束条件 当前的
      operation_input = operation_input.substr(index + 1);  // 处理剩余字符串
    }
  }
};
// @lc code=end
