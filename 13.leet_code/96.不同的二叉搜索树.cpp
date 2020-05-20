/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  // 动态规划问题求解(动态规划是自下向上(有点类似高中的数列思想,找到合适的函数))
  // 设G(n)为含n个节点的二叉树的数量 F(i,n)为以i为根节点的二叉树数量
  // F(i,n)退化为其左子树(i-1)个节点的数量* 右子树(n-i)个节点的数量
  // 即：F(i,n) = G(i-1) * G(n-1)
  // G(n)可以表述为以每个节点为根节点的所有二叉树数量之和
  // 即：G(n) = F(0) + F(1) + F(2) + ... + F(n)
  // 即：G(n) = sum(i=0..n){G(i-1)*G(n-i)}
  int numTrees(int n) {
    if (n < 2) return 1;
    vector<int> G(n + 1, 0);  // 命名和上面解释保持一致 方便理解
    G[0] = 1;
    // 注意i的初始化 可以从1 也可以从2开始 从1开始的话则不需要指定G[1] = 1
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        G[i] += G[j - 1] * G[i - j];
      }
    }
    return G[n];
  }

  // 递归的解决方式 递归是自顶向下(提交有超时问题)
  int NumTreeDiGuiImp(int n) {
    if (n == 1 || n == 0) return 1;
    int result = 0;
    for (int i = 1; i <= n; ++i) {
      result += (NumTreeDiGuiImp(i - 1) * NumTreeDiGuiImp(n - i));
    }
    return result;
  }
};
// @lc code=end
