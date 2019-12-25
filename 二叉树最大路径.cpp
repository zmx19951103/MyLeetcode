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
 int helper(TreeNode* root) {
     
     // 求树直径的做法
        int val = root->val;
        int left_val=0,right_val=0;
        if(root->left) left_val = helper(root->left);
        if(root->right) right_val = helper(root->right);

         int temp=val;
          if(left_val>0)val+=left_val;
          if(right_val>0)val+=right_val;

         if(val>res)res = val;
         
         return std::max(std::max(left_val,right_val),0) + temp;



 }
    int maxPathSum(TreeNode* root) {
      helper(root);
      return res;       
        
    }
    int res = INT_MIN;
};