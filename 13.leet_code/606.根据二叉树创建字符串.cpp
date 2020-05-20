/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
using namespace std;

class Solution {
 public:
  string tree2str(TreeNode* t) {
    // 分析递归结束的四种情况
    if (t == NULL) {
      return "";
    } else if (t->left == NULL && t->right == NULL) {
      return to_string(t->val);
    } else if (t->right == NULL) {
      return to_string(t->val) + "(" + tree2str(t->left) + ")";
    }
    return to_string(t->val) + "(" + tree2str(t->left) + ")(" +
           tree2str(t->right) + ")";
  }
};
// @lc code=end
