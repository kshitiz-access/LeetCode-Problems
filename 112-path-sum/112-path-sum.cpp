/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    stack<pair<TreeNode*, int>> stk;
    stk.push({root, sum});
    while (!stk.empty()) {
      auto [node, curr_sum] = stk.top();
      stk.pop();
      curr_sum -= node->val;
      if (!node->left && !node->right && curr_sum == 0) {
        return true;
      }
      if (node->right) stk.push({node->right, curr_sum});
      if (node->left) stk.push({node->left, curr_sum});
    }
    return false;
  }
};