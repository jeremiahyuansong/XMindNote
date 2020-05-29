/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
 public:
  // 思路：每个小时要吃的最小的值为:TotalNum/H
  // 从这个值开始递增,到TotalNum为截止(一次把所有香蕉吃完，应该不会遍历到这)
  // 然后判断每一堆里面 piles[i]/k + 1/0(取决于piles[i]%k）
  // 判断总的小时数是否<=H 小于的话表示找到结果

  int minEatingSpeed(vector<int>& piles, int H) {
    long int total_num = 0;
    for (size_t i = 0; i < piles.size(); ++i) {
      total_num += piles[i];
    }
    int start_k = total_num / H;
    start_k = (start_k == 0) ? 1 : start_k;  // 解决[312884470]/n968709470
    for (; start_k < total_num; ++start_k) {
      int cost_hour = 0;
      for (size_t i = 0; i < piles.size(); ++i) {
        int shang = piles[i] / start_k;
        int yushu = piles[i] % start_k;
        cost_hour = cost_hour + ((yushu == 0) ? shang : shang + 1);
      }
      if (cost_hour <= H) {
        break;
      }
    }
    return start_k;
  }
};
// @lc code=end
