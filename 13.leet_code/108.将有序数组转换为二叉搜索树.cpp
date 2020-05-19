/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBstImp(nums, 0, nums.size() - 1);
  }

 private:
  // 中序遍历树 逆过程
  TreeNode* sortedArrayToBstImp(const vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBstImp(nums, left, mid - 1);
    root->right = sortedArrayToBstImp(nums, mid + 1, right);
    return root;
  }
};
// @lc code=end
