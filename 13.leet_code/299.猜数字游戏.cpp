/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start

#include <math.h>

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string getHintNoUse(string secret, string guess) {
    auto cal_char_index = [](const string input,
                             unordered_map<string, unordered_set<int>> &result) {
      for (int i = 0; i < input.size(); ++i) {
        // char ->string 的方法 使用单个元素进行构造
        auto find_iter = result.find(string(1, input[i]));
        if (find_iter != result.end()) {
          find_iter->second.emplace(i);
        } else {
          auto temp = make_pair<string, unordered_set<int>>(string(1, input[i]), {i});
          result.insert({string(1, input[i]), {i}});
        }
      }
    };

    unordered_map<string, unordered_set<int>> secret_result = {};
    unordered_map<string, unordered_set<int>> guess_result = {};
    int a_num = 0, b_num = 0;
    cal_char_index(secret, secret_result);
    cal_char_index(guess, guess_result);
    for (auto guess_item : guess_result) {
      auto find_iter = secret_result.find(guess_item.first);
      if (find_iter != secret_result.end()) {
        int same_count = 0;
        for (auto guess_index : guess_item.second) {
          if (find_iter->second.count(guess_index) != 0) {
            // 数字相同位置也相同的元素
            a_num++;
            same_count++;
          }
        }
        // 数字相同 位置不同
        b_num +=
            std::min(guess_item.second.size() - same_count, find_iter->second.size() - same_count);
      }
    }
    return to_string(a_num) + "A" + to_string(b_num) + "B";
  }

  /**
   * 我上面的那种思路的方式 把每个相同位置地方的元素的index的详细位置都保留下来了，其实没有必要
   * 只用统计各个数字的count即可
   *
   * */
  string getHint(string secret, string guess) {
    int a_num = 0, b_num = 0;
    vector<int> secret_result(10, 0);
    vector<int> guess_result(10, 0);
    for (size_t i = 0; i < guess.size(); ++i) {
      if ((secret[i] - '0') == (guess[i] - '0')) {
        a_num++;
      } else {
        secret_result[secret[i] - '0']++;
        guess_result[guess[i] - '0']++;
      }
    }
    for (size_t i = 0; i < secret_result.size(); ++i) {
      b_num += std::min(secret_result[i], guess_result[i]);
    }
    return to_string(a_num) + "A" + to_string(b_num) + "B";
  }
};
// @lc code=end
