/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // 思路：题目给出的nums1应该充分利用 可以从后往前降序排
    int final = m + n - 1;
    while (n) {
      // m==0表示nums1中的元素提前结束 后面所有的填充nums2的
      // nums2中的元素结束的情况补充nums1的是由于final=m+n-1和while(n)保证
      if (m == 0 || nums2[n - 1] >= nums1[m - 1]) {
        // nums1[final] = nums2[n - 1];
        // final--;
        // n--;
        nums1[final--] = nums2[--n];
      } else {
        // nums1[final] = nums1[m - 1];
        // final--;
        // m--;
        nums1[final--] = nums1[--m];
      }
    }
  }
};
// @lc code=end
